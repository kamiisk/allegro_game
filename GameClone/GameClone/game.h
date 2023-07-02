#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "functions.h"


void incrementa_score(int* score);
void ver_eventos(ALLEGRO_EVENT_QUEUE* event_queue, int* pos_x, int* pos_y, ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_BITMAP* sprit_inimigo, int* score);
