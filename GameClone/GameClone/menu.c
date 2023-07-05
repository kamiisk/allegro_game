#include "menu.h"

void menu_inicial(ALLEGRO_FONT* font, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {
    bool menu_aberto = true;
    int selecionado = 0;

    while (menu_aberto) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                selecionado--;
                if (selecionado < 0) {
                    selecionado = 0;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                if (!menu_aberto) {
                    break;
                }
                selecionado++;
                if (selecionado > 3) {
                    selecionado = 3;
                }
                break;
            case ALLEGRO_KEY_ENTER:
                if (selecionado == 0) {
                    // Inicia o jogo ao selecionar a opção "Jogar"
                    menu_aberto = false;
                }
                else if (selecionado == 1) {
                    // Abre as opções de som ao selecionar a opção "Som"
                    // Implemente aqui a lógica para as opções de som
                }
                else if (selecionado == 2) {


                }
                else {
                    exit(0); // Fecha o jogo ao selecionar a opção "Sair"
                }
                break;
            default:
                break;
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(font, (selecionado == 0) ? al_map_rgb(255, 255, 255) : al_map_rgb(128, 128, 128), 400, 300 - 80, ALLEGRO_ALIGN_CENTER, "Jogar");
        al_draw_text(font, (selecionado == 1) ? al_map_rgb(255, 255, 255) : al_map_rgb(128, 128, 128), 400, 300 - 40, ALLEGRO_ALIGN_CENTER, "som");
        al_draw_text(font, (selecionado == 2) ? al_map_rgb(255, 255, 255) : al_map_rgb(128, 128, 128), 400, 300, ALLEGRO_ALIGN_CENTER, "Manual Anti-Burro");
        al_draw_text(font, (selecionado == 3) ? al_map_rgb(255, 255, 255) : al_map_rgb(128, 128, 128), 400, 300 + 40, ALLEGRO_ALIGN_CENTER, "Sair");
        al_flip_display();
    }
}
