#include "game.h"

typedef struct {
    int pos_x;
    int pos_y;
    bool queda;
    bool visivel;
    //float tempo_queda;
}Torre;

void incrementa_score(int* score) {
    (*score)++;
}

void ver_eventos(ALLEGRO_EVENT_QUEUE* event_queue, int* pos_x, int* pos_y, ALLEGRO_FONT* font, ALLEGRO_BITMAP* sprit, ALLEGRO_BITMAP* sprit_inimigo, ALLEGRO_BITMAP* fundo, int* score) {
    ALLEGRO_EVENT event;
    // Torre torre[NUN_TORRE]; // Array de torres
    Torre torre;

    torre.pos_x = pozicione_naoaliado();
    torre.pos_y = -50;
    torre.queda = false;
    torre.visivel = true;
    //torre.tempo_queda = 0.15;

    float velocidade = 15;
    int num_torres = 0;
    bool colidiu = false;
    

    bool move_left = false;
    bool move_right = false;

    do {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_RIGHT:
                move_right = true;
                break;
            case ALLEGRO_KEY_LEFT:
                move_left = true;
                break;
            default:
                break;
            }
        }
        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_RIGHT:
                move_right = false;
                break;
            case ALLEGRO_KEY_LEFT:
                move_left = false;
                break;
            default:
                break;
            }
        }
       
        desenha_tela(font, sprit,fundo, *pos_x, *pos_y, *score);
        desenha_inimigo(sprit_inimigo, torre.pos_x, torre.pos_y);

        if (torre.pos_y > 500) {
            torre.pos_x = pozicione_naoaliado();
            torre.pos_y = -50;
            num_torres++;

            if (colidiu) {
                incrementa_score(score);
                colidiu = false;
                torre.visivel = false;
            }
        }
        if (torre.visivel) {
            desenha_inimigo(sprit_inimigo, torre.pos_x, torre.pos_y);
        }

        float pos_player = *pos_x;
        float pos_torre_inimiga = torre.pos_x;

        if (pos_player > pos_torre_inimiga - 50 && pos_player < pos_torre_inimiga + 50 && torre.pos_y > 0 && torre.pos_y < 500) {
            colidiu = true;
        }
 
        switch (num_torres) {
        case 3:
            velocidade = 5;
            break;

        case 10:
            velocidade = 15;
            break;

        case 20:
            velocidade = 20;
            break;

        default:
            break;
        }
        torre.pos_y += velocidade;

        if (move_right && *pos_x < 740)
            *pos_x += 10;

        if (move_left && *pos_x > 0)
            *pos_x -= 10;
    } while (event.type != ALLEGRO_EVENT_DISPLAY_CLOSE);
}

