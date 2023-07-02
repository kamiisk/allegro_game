#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ALLEGRO_DISPLAY* inicia_display();
ALLEGRO_EVENT_QUEUE* inicia_event_queue(ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer);
void desenha_tela(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, int pos_x, int pos_y, int score);
void limpeza_divina(ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void desenha_inimigo(ALLEGRO_BITMAP* sprit, int pos_x, int pos_y);
int pozicione_naoaliado();
void inicializa_aleatorio();