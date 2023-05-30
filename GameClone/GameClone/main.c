#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




typedef struct {
    int pos_x;
    int pos_y;
    bool queda;
}varias_torres;

ALLEGRO_DISPLAY* inicia_display(); 
ALLEGRO_EVENT_QUEUE* inicia_event_queue(ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer);
void desenha_tela(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, int pos_x, int pos_y);
void ver_eventos(ALLEGRO_EVENT_QUEUE* event_queue, int* pos_x, int* pos_y, ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_BITMAP* sprit_inimigo);
void limpeza_divina(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void desenha_inimigo(ALLEGRO_BITMAP* sprit, int pos_x, int pos_y);
int pozicione_naoaliado();
void inicializa_aleatorio();

int main (){
  //Inicia a biblioteca e todas as dependencias que vão ser usadas
  al_init();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();
  al_install_keyboard();
  al_init_primitives_addon();


  //DISPLAY//
  ALLEGRO_DISPLAY* display = inicia_display();

  // LOAD ASSETS // Declarando assets e carregando para uma variavel
  ALLEGRO_FONT* font = al_load_font("./Assets/font.ttf",15,0);
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  ALLEGRO_BITMAP* sprit = al_load_bitmap("./Assets/Tower.png");
  ALLEGRO_BITMAP* sprit_inimigo = al_load_bitmap("./Assets/enemy_tower.png");

  //Verificador de eventos todos os eventos tem que passar por aqui
  ALLEGRO_EVENT_QUEUE* event_queue = inicia_event_queue(display, timer);
  al_start_timer(timer);

  //VARIAVEIS DE POSIÇÂO E FPS (CASO ANIMAÇÂO COM VARIOS SPRITES)
  //float frame = 0.f;
  //int posicao_ini_sprite = 161;
  int pos_x = 0, pos_y = 500;

  ver_eventos(event_queue, &pos_x, &pos_y, font, sprit, sprit_inimigo);

  limpeza_divina(font, sprit, display, event_queue);

  return 0;
}

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


void ver_eventos(ALLEGRO_EVENT_QUEUE* event_queue, int *pos_x, int *pos_y, ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_BITMAP* sprit_inimigo) {
    ALLEGRO_EVENT event;
    int y = -50, x = pozicione_naoaliado();
    do {
        al_wait_for_event(event_queue, &event);
        desenha_tela(font, sprit, *pos_x, *pos_y);
        desenha_inimigo(sprit_inimigo, x, y);
        y += 8;
        if (y > 500){
            x = pozicione_naoaliado();
            y = -50;
        }
        


        
        switch (event.keyboard.keycode)
        {
            case ALLEGRO_KEY_RIGHT:
                if(*pos_x<740)
                    *pos_x += 20;
            break;
            case ALLEGRO_KEY_LEFT:
                if(*pos_x > 0)
                    *pos_x -= 20;
            break;
            default:
                break;
        }
    } while (event.type != ALLEGRO_EVENT_DISPLAY_CLOSE);
}

void desenha_tela(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, int pos_x, int pos_y) {
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font, al_map_rgb(0, 0, 0), 10, 10, 0, "SCORE:");
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, 9, 0, "SCORE:");
    al_draw_bitmap(sprit, pos_x, pos_y, 0);
    al_flip_display();
}

void limpeza_divina(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue){
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