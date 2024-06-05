/*
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

using namespace std;

ALLEGRO_DISPLAY* janela = NULL;
ALLEGRO_EVENT_QUEUE* fEventos = NULL;
ALLEGRO_EVENT ev;

ALLEGRO_BITMAP* chao = al_load_bitmap("./bitmap/chao.png");
ALLEGRO_BITMAP* parede = NULL;
ALLEGRO_BITMAP* porta = NULL;
ALLEGRO_BITMAP* centro_lousa = NULL;
ALLEGRO_BITMAP* esquerda_lousa = NULL;
ALLEGRO_BITMAP* direita_lousa = NULL;

const int linha = 11;
const int coluna = 15;
int mapa[linha][coluna] = { {2,2,2,2,2,7,5,5,5,6,2,2,2,2,2},
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


    janela = al_create_display(32*11, 32*15);
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
        al_wait_for_event(fEventos, &ev);
        al_draw_bitmap(chao,1*32,1*32,0);

    }

    return 0;
}
*/
#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>

#define BLOCKSIZE 32
#define WMAPA 15
#define HMAPA 11
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*HMAPA

enum KEYS{UP, DOWN, LEFT, RIGHT};
enum KEYS2{W, S, A, D};

int mapa[HMAPA][WMAPA] = {
                     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1},
                     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 1},
                     { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 2, 1},
                     { 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 2, 1},
                     { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 0, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 0, 0, 1},
                     { 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
                     { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                     { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
                     { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
                   };

ALLEGRO_BITMAP *chao = al_load_bitmap("./bitmap/chao.png");

void DrawMap(){

  for(int i=0; i<HMAPA; i++){
    for(int j=0; j<WMAPA; j++){
      int x=mapa[i][j] % 3 * BLOCKSIZE;
      int y=mapa[i][j] / 3 * BLOCKSIZE;
      int dx=j*BLOCKSIZE;
      int dy=i*BLOCKSIZE;

      al_draw_scaled_bitmap(chao,i,j,32,32,dx,dy,32,32,0);

    }
  }
}
bool colide(int x, int y){
   int dx=x/BLOCKSIZE;
   int dy=y/BLOCKSIZE;
   int dx1=(x+25)/BLOCKSIZE;
   int dy1=(y+25)/BLOCKSIZE;


   if (mapa[dy][dx]==1 || mapa[dy][dx1]==1
       || mapa[dy1][dx]==1 || mapa[dy1][dx1]==1)
     return true;
   return false;
}
bool colideFantasma(int px, int py, int fx, int fy){

   if (px+BLOCKSIZE >= fx &&
       px <= fx + BLOCKSIZE &&
       py + BLOCKSIZE >= fy &&
       py <= fy + BLOCKSIZE)
    {
     return true;
    }
   return false;
}

int main(){

    ALLEGRO_DISPLAY *display;

    const float FPS = 100.0;
    bool done = false;
    bool redesenha=true;
    int posX = 35;
    int posY = 35;
    int posX2 = 265;
    int posY2 = 265;

    bool keys[4] = {false, false, false, false};
    bool keys2[4] = {false, false, false, false};

    al_init();
    display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
    al_set_window_position(display, 300, 200);

    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    ALLEGRO_BITMAP *player2 = al_load_bitmap("Fantasma.png");
    ALLEGRO_BITMAP *player = al_load_bitmap("pacman.png");

    al_start_timer(timer);
    bool mostraFantasma = true;
    while(!done){
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        ALLEGRO_EVENT_TYPE tipoEvento=events.type;
        switch (tipoEvento) {
          case ALLEGRO_EVENT_TIMER: { redesenha=true; break;}
          case ALLEGRO_EVENT_DISPLAY_CLOSE: { done = true; break;}
          case ALLEGRO_EVENT_KEY_DOWN: {
            int tecla = events.keyboard.keycode;
            switch(tecla){
                case ALLEGRO_KEY_UP: {keys[UP] = true; break;}
                case ALLEGRO_KEY_DOWN: {keys[DOWN] = true; break;}
                case ALLEGRO_KEY_LEFT: {keys[LEFT] = true; break;}
                case ALLEGRO_KEY_RIGHT: {keys[RIGHT] = true; break;}
            }
            break;
          }
          case ALLEGRO_EVENT_KEY_UP: {
            int tecla = events.keyboard.keycode;
            switch(tecla){
                case ALLEGRO_KEY_UP: {keys[UP] = false; break;}
                case ALLEGRO_KEY_DOWN: {keys[DOWN] = false;break; }
                case ALLEGRO_KEY_LEFT: {keys[LEFT] = false; break;}
                case ALLEGRO_KEY_RIGHT: {keys[RIGHT] = false; break;}
                case ALLEGRO_KEY_ESCAPE: {done = true; break; }
            }
            break;
          }
        }

        if (!colide(posX, posY-2))
           posY -= keys[UP] * 2;

        if (!colide(posX, posY+2))
           posY += keys[DOWN] * 2;

        if (!colide(posX-2, posY))
           posX -= keys[LEFT] * 2;

        if (!colide(posX+2, posY))
           posX += keys[RIGHT] * 2;

        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys2[W] = true;
                    break;
                case ALLEGRO_KEY_S:
                    keys2[S] = true;
                    break;
                case ALLEGRO_KEY_A:
                    keys2[A] = true;
                    break;
                case ALLEGRO_KEY_D:
                    keys2[D] = true;
                    break;
            }
            if (colideFantasma(posX, posY, posX2, posY2)){
                mostraFantasma=false;
            }
        }
        else if(events.type == ALLEGRO_EVENT_KEY_UP) {
            switch(events.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys2[W] = false;
                    break;
                case ALLEGRO_KEY_S:
                    keys2[S] = false;
                    break;
                case ALLEGRO_KEY_A:
                    keys2[A] = false;
                    break;
                case ALLEGRO_KEY_D:
                    keys2[D] = false;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
            }
        }

        posY2 -= keys2[W] * 2;
        posY2 += keys2[S] * 2;
        posX2 -= keys2[A] * 2;
        posX2 += keys2[D] * 2;

        if (redesenha) {
          DrawMap();

          al_draw_bitmap(player, posX, posY, 0);
          if (mostraFantasma){
             al_draw_bitmap(player2, posX2, posY2, 0);
          }
          al_flip_display();
          redesenha=false;
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}

