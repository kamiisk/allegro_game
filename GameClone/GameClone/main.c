#include "menu.h""
#include "functions.h"
#include "game.h"

int main() {
    // Inicia a biblioteca e todas as dependências que serão usadas
    if (!al_init()) {
        fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
        return 1;
    }
    printf("Biblioteca Allegro inicializada com sucesso.\n");

    if (!al_init_font_addon()) {
        fprintf(stderr, "Falha ao inicializar o addon de fonte da Allegro.\n");
        return 1;
    }
    printf("Addon de fonte da Allegro inicializado com sucesso.\n");

    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Falha ao inicializar o addon TrueType Font da Allegro.\n");
        return 1;
    }
    printf("Addon TrueType Font da Allegro inicializado com sucesso.\n");

    if (!al_init_image_addon()) {
        fprintf(stderr, "Falha ao inicializar o addon de imagem da Allegro.\n");
        return 1;
    }
    printf("Addon de imagem da Allegro inicializado com sucesso.\n");

    if (!al_install_keyboard()) {
        fprintf(stderr, "Falha ao instalar o teclado da Allegro.\n");
        return 1;
    }
    printf("Teclado da Allegro instalado com sucesso.\n");

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Falha ao inicializar o addon de primitivas da Allegro.\n");
        return 1;
    }
    printf("Addon de primitivas da Allegro inicializado com sucesso.\n");

    // DISPLAY
    ALLEGRO_DISPLAY* display = inicia_display();
    if (!display) {
        fprintf(stderr, "Falha ao criar o display da Allegro.\n");
        return 1;
    }
    printf("Display criado com sucesso.\n");

    // LOAD ASSETS
    ALLEGRO_FONT* font = al_load_font("./Assets/font.ttf", 15, 0);
    if (!font) {
        fprintf(stderr, "Falha ao carregar a fonte.\n");
        al_destroy_display(display);
        return 1;
    }
    printf("Fonte carregada com sucesso.\n");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    if (!timer) {
        fprintf(stderr, "Falha ao criar o timer da Allegro.\n");
        al_destroy_font(font);
        al_destroy_display(display);
        return 1;
    }
    printf("Timer criado com sucesso.\n");

    ALLEGRO_BITMAP* fundo = al_load_bitmap("./Assets/background_torres.png");
    if (!fundo) {
        fprintf(stderr, "Falha ao carregar a imagem de fundo.\n");
        al_destroy_timer(timer);
        al_destroy_font(font);
        al_destroy_display(display);
        return 1;
    }
    printf("Bitmap do background carregado com sucesso.\n");

    ALLEGRO_BITMAP* sprit = al_load_bitmap("./Assets/Tower.png");
    if (!sprit) {
        fprintf(stderr, "Falha ao carregar o bitmap da torre.\n");
        al_destroy_timer(timer);
        al_destroy_font(font);
        al_destroy_display(display);
        return 1;
    }
    printf("Bitmap da torre carregado com sucesso.\n");

    ALLEGRO_BITMAP* sprit_inimigo = al_load_bitmap("./Assets/invertedpawn.png");
    if (!sprit_inimigo) {
        fprintf(stderr, "Falha ao carregar o bitmap da torre inimiga.\n");
        al_destroy_bitmap(sprit);
        al_destroy_timer(timer);
        al_destroy_font(font);
        al_destroy_display(display);
        return 1;
    }
    printf("Bitmap da torre inimiga carregado com sucesso.\n");

    // Verificador de eventos - todos os eventos têm que passar por aqui
    ALLEGRO_EVENT_QUEUE* event_queue = inicia_event_queue(display, timer);
    if (!event_queue) {
        fprintf(stderr, "Falha ao criar a fila de eventos da Allegro.\n");
        al_destroy_bitmap(sprit_inimigo);
        al_destroy_bitmap(sprit);
        al_destroy_timer(timer);
        al_destroy_font(font);
        al_destroy_display(display);
        return 1;
    }
    printf("Fila de eventos criada com sucesso.\n");

    al_start_timer(timer);

    int score = 0;
    menu_inicial(font, display, event_queue);

    int pos_x = 0, pos_y = 500;

    ver_eventos(event_queue, &pos_x, &pos_y, font, sprit, sprit_inimigo,fundo , &score);

    limpeza_divina(font, sprit,sprit_inimigo,fundo, display, event_queue);

    return 0;
}
