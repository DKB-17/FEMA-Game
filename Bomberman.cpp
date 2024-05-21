#include <iostream>
#include <allegro.h>
#include <allegro_image.h>
#include <keyboard.h>

using namespace std;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fEventos = NULL;
ALLEGRO_EVENT ev;

void desenhaMapa(){

}

int main(){

    int tamanho_mapa = 20;
    int mapa[14][20] = {        {0,0,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,1,0,0},
                                {0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,0},
                                {1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,1,1},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0},
                                {1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0}
                                };

    al_init();
    al_init_image_addon();
    al_install_keyboard();


    janela = al_create_display(500,500);
    al_set_window_position(janela, 100,100);
    al_set_window_title(janela, "BOMBERMAN");

    float FPS = 60;

    ALLEGRO_TIMER *timer = al_create_timer(1/FPS);

    fEventos = al_create_event_queue();
    al_register_event_source(fEventos, al_get_display_event_source(janela));
    al_register_event_source(fEventos, al_get_timer_event_source(timer));
    al_register_event_source(fEventos, al_get_keyboard_event_source());


    al_start_timer(timer);
    bool done = false;
    while(!done){

        al_wait_for_event(fEventos, &ev);
        al_flip_display();
    }

    return 0;
}
