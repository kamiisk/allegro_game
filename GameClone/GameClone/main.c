#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

int main (){
  //Inicia a biblioteca e todas as dependencias que vão ser usadas
  al_init();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();
  al_install_keyboard();

  //DISPLAY//
  ALLEGRO_DISPLAY * display = al_create_display(800,600);
  al_set_window_position(display, 200, 200);
  al_set_window_title(display, "CloneGame");

  // LOAD ASSETS // Declarando assets e carregando para uma variavel
  ALLEGRO_FONT* font = al_load_font("./Assets/font.ttf",15,0);
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);

  ALLEGRO_BITMAP* sprit = al_load_bitmap("./Assets/Tower.png");

  //Verificador de eventos todos os eventos tem que passar por aqui
  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_start_timer(timer);

  //VARIAVEIS DE POSIÇÂO E FPS (CASO ANIMAÇÂO COM VARIOS SPRITES)
  //float frame = 0.f;
  //int posicao_ini_sprite = 161;
  int pos_x = 0, pos_y = 500;

  

  while(true){
    ALLEGRO_EVENT event;   
    al_wait_for_event(event_queue, &event);
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){ 
      break;
    }else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        pos_x += 20;
    }
    else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
        pos_x -= 20;
    }
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font, al_map_rgb(0, 0, 0), 10, 10, 0, "SCORE:");
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, 9, 0, "SCORE:");
    al_draw_bitmap(sprit, pos_x, pos_y,0);
    al_flip_display();
  }

  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_bitmap(sprit);

  return 0;
}