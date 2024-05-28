#include <iostream>
#include <allegro.h>
#include <allegro_image.h>
#include <keyboard.h>

using namespace std;

ALLEGRO_DISPLAY* janela = NULL;
ALLEGRO_EVENT_QUEUE* fEventos = NULL;
ALLEGRO_EVENT ev;

ALLEGRO_BITMAP* chao = NULL;
ALLEGRO_BITMAP* parede = NULL;
ALLEGRO_BITMAP* porta = NULL;
ALLEGRO_BITMAP* centro_lousa = NULL;
ALLEGRO_BITMAP* esquerda_lousa = NULL;
ALLEGRO_BITMAP* direita_lousa = NULL;

int mapa[11][15] = { {2,2,2,2,2,7,5,5,5,6,2,2,2,2,2},
                                {2,0,0,1,1,0,1,1,0,0,1,1,0,0,3},
                                {2,0,4,1,4,1,4,0,4,1,4,1,4,0,2},
                                {2,1,0,1,1,0,1,0,1,1,0,1,1,1,2},
                                {2,0,4,1,4,0,4,0,4,1,4,1,4,1,2},
                                {2,1,0,1,0,1,1,1,0,1,0,1,0,1,2},
                                {2,0,4,1,4,0,4,0,4,1,4,1,4,0,2},
                                {2,1,1,1,1,1,1,1,1,1,0,1,1,1,2},
                                {2,0,4,1,4,1,4,0,4,1,4,1,4,0,2},
                                {2,0,0,1,1,0,1,0,1,1,0,1,0,0,2},
                                {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};  // 0 - chao da sala
// 1 - prova com nota 0
// 2 - parede da sala
// 3 - porta
// 4 - mesa de aula
// 5 - meio da lousa
// 6 - canto direito da lousa
// 7 - canto esquerdo da lousa
// 8 - personagem
// 9 - bomba
// 10 - explosao

void desenhaMapa() {

}

int main() {


    al_init();
    al_init_image_addon();
    al_install_keyboard();


    janela = al_create_display(500, 500);
    al_set_window_position(janela, 100, 100);
    al_set_window_title(janela, "BOMBERMAN");

    const float FPS = 60;

    ALLEGRO_TIMER* timer = al_create_timer(1 / FPS);

    fEventos = al_create_event_queue();
    al_register_event_source(fEventos, al_get_display_event_source(janela));
    al_register_event_source(fEventos, al_get_timer_event_source(timer));
    al_register_event_source(fEventos, al_get_keyboard_event_source());


    al_start_timer(timer);
    bool done = false;
    while (!done) {


    }

    return 0;
}
