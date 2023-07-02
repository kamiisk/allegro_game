 #include "functions.h"
#include "game.h"



ALLEGRO_DISPLAY* inicia_display();
ALLEGRO_EVENT_QUEUE* inicia_event_queue(ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer);
void desenha_tela(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, int pos_x, int pos_y, int score);
void limpeza_divina(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void desenha_inimigo(ALLEGRO_BITMAP* sprit, int pos_x, int pos_y);
int pozicione_naoaliado();
void inicializa_aleatorio();

typedef struct {
    int pos_x;
    int pos_y;
    bool queda;
  
}Torre;



ALLEGRO_DISPLAY* inicia_display() {
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    al_set_window_position(display, 200, 200);
    al_set_window_title(display, "CloneGame");

    return display;
}

ALLEGRO_EVENT_QUEUE* inicia_event_queue(ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer) {
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    return event_queue;
}

void desenha_tela(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, int pos_x, int pos_y,  int score) {
    al_clear_to_color(al_map_rgb(255, 255, 255));

    // Desenha o grid
    for (int x = 0; x < 800; x += 25) {
        al_draw_line(x, 0, x, 600, al_map_rgb(200, 200, 200), 1);
    }

    for (int y = 0; y < 600; y += 25) {
        al_draw_line(0, y, 800, y, al_map_rgb(200, 200, 200), 1);
    }
    ////////////////////////////////////////////////////////////////////////
    char score_text[20];
    snprintf(score_text, sizeof(score_text), "SCORE: %d", score);

    al_draw_text(font, al_map_rgb(255, 255, 255),10, 10, 0, score_text);
    al_draw_text(font, al_map_rgb(0, 0, 0),11, 11, 0, score_text);

    al_draw_bitmap(sprit, pos_x, pos_y, 0);

    al_flip_display();

}

bool verifica_colisao(int x1, int y1, int largura1, int altura1, int x2, int y2, int largura2, int altura2) {
    // Verifica se ocorre colisão nas coordenadas X
    bool colisaoX = x1 + largura1 >= x2 && x2 + largura2 >= x1;

    // Verifica se ocorre colisão nas coordenadas Y
    bool colisaoY = y1 + altura1 >= y2 && y2 + altura2 >= y1;

    // Retorna verdadeiro se ocorrer colisão em ambas as coordenadas
    return colisaoX && colisaoY;
}



void limpeza_divina(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(sprit);
}

void desenha_inimigo(ALLEGRO_BITMAP* sprit, int pos_x, int pos_y) {
    al_draw_bitmap(sprit, pos_x, pos_y, 0);
    al_flip_display();
}

int pozicione_naoaliado() {
    int x = rand() % 730;
    printf("%d\n", x);
    return x;
}

void inicializa_aleatorio() {
    srand(time(NULL));
}
