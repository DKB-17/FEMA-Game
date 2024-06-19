#include <iostream>
#include <allegro.h>
#include <allegro_font.h>
#include <allegro_image.h>
#include <keyboard.h>
#include <allegro_primitives.h>

#define BLOCO 32
#define WMAPA 50
#define HMAPA 25


using namespace std;


int mapa[HMAPA][WMAPA] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3,10, 5, 5, 5, 5, 5, 5, 5, 5,10, 1, 1, 1, 1,10, 5, 5, 5, 5,10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 4, 8, 8, 8, 8, 8, 0, 0, 0,-6, 1, 1, 1, 1, 4, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 6, 5, 6, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 9, 0, 4, 1, 1, 1, 1, 4, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 9, 0, 9, 0, 9, 0, 9, 0, 4, 1, 1, 1, 1,10, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 9, 0, 4, 1, 1, 1, 1, 1, 1, 6, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 9, 0, 9, 0, 9, 0, 9, 0, 4, 1, 1, 1, 1, 1,10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 9, 0, 4, 1, 1, 1, 1, 1, 1, 6, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 9, 0, 9, 0, 9, 0, 9, 0, 4, 1, 1, 1, 1,10, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 9, 0, 4, 1, 1, 1, 1, 4, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 9, 0, 9, 0, 9, 0, 9, 0, 4, 1, 1, 1, 1, 4, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2},
{10,6, 5, 5, 5, 5, 6, 5, 5, 5, 5,10, 5, 6, 5, 5, 5, 5, 5, 6,10, 1, 1, 1, 1,10, 5, 5, 5, 5,10, 5, 5, 5, 5, 5, 6,10, 6, 5, 5, 5, 6,10, 1, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 7, 2, 2, 1, 1, 1, 1, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,10, 1, 1, 1, 1,10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 1, 1, 1, 1, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 1, 1, 1, 1, 4, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2}
};

/**

    - 0 Chao Piso
    - 1 Corredor
    - 2 Grama
    - 3 Telhado
    - 4 Parede
    - 5 Parede Cima
    - -6 PortaDir
    - 6 Porta
    - 7 Arvore
    - 8 Mesa cima
    - 9 Mesa Direita
    - 10 Canto

*/

ALLEGRO_BITMAP *piso = NULL;
ALLEGRO_BITMAP *corredor = NULL;
ALLEGRO_BITMAP *grama = NULL;
ALLEGRO_BITMAP *parede = NULL;
ALLEGRO_BITMAP *paredeFrent = NULL;
ALLEGRO_BITMAP *mesa = NULL;
ALLEGRO_BITMAP *mesaDir = NULL;
ALLEGRO_BITMAP *arvore = NULL;
ALLEGRO_BITMAP *telhado = NULL;
ALLEGRO_BITMAP *porta = NULL;
ALLEGRO_BITMAP *portaDir = NULL;
ALLEGRO_BITMAP *canto = NULL;

void DesenharMapa(){
    for(int i=0; i<HMAPA; i++){
        for(int j=0; j<WMAPA; j++){
            int dx = BLOCO*j, dy = BLOCO*i;
            if(mapa[i][j] == 0) {
                al_draw_bitmap(piso,dx,dy,0);
            } else if(mapa[i][j] == 1) {
                al_draw_bitmap(corredor,dx,dy,0);
            } else if(mapa[i][j] == 2) {
                al_draw_bitmap(grama,dx,dy,0);
            } else if(mapa[i][j] == 3) {
                al_draw_bitmap(telhado,dx,dy,0);
            } else if(mapa[i][j] == 4) {
                al_draw_bitmap(parede,dx,dy,0);
            } else if(mapa[i][j] == 5) {
                al_draw_bitmap(paredeFrent,dx,dy,0);
            } else if(mapa[i][j] == 6) {
                al_draw_bitmap(porta,dx,dy,0);
            } else if(mapa[i][j] == -6) {
                al_draw_bitmap(portaDir,dx,dy,0);
            } else if(mapa[i][j] == 8) {
                al_draw_bitmap(mesa,dx,dy,0);
            } else if(mapa[i][j] == 9) {
                al_draw_bitmap(mesaDir,dx,dy,0);
            } else if(mapa[i][j] == 10) {
                al_draw_bitmap(canto,dx,dy,0);
            }
        }
    }
}
void DesenharArvore() {
    for(int i=0; i<HMAPA; i++){
        for(int j=0; j<WMAPA; j++){
            int dx = BLOCO*j, dy = BLOCO*i;
            if(mapa[i][j] == 7) {
                al_draw_bitmap(arvore,dx-57,dy-180,0);
            }
        }
    }
}


int main(){

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_init_primitives_addon();


    //ALLEGRO_BITMAP* iconePage = al_load_bitmap("");
    ALLEGRO_DISPLAY *display = al_create_display(WMAPA*BLOCO,HMAPA*BLOCO);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_window_position(display, 0,5);
    al_set_window_title(display, "BritoMen");
    //al_set_display_icon(display, iconePage);

    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(1.0/60.0);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    // altura = 32
    // comprimento = 32
    ALLEGRO_BITMAP *person1 = al_load_bitmap("./personagem/py1 - Bomberman.png");
    float frame1 = 0.f;
    int current_frame_x1 = 0;
    int current_frame_y1 = 0;
    int inverte = 0;
    int pos_x1 = 0;
    int pos_y1 = 0;

    // altura = 384 / 4 = 96
    // comprimento = 256 / 4 = 64
    ALLEGRO_BITMAP *person2 = al_load_bitmap("./personagem/personagem1.png");
    float frame2 = 0.f;
    int current_frame_x2 = 0;
    int current_frame_y2 = 96;
    int pos_x2 = 1280-64;
    int pos_y2 = 0;

    piso = al_load_bitmap("../bitmap/piso.png");
    corredor = al_load_bitmap("../bitmap/corredor.png");
    grama = al_load_bitmap("../bitmap/grama.png");
    parede = al_load_bitmap("../bitmap/parede.png");
    paredeFrent = al_load_bitmap("../bitmap/paredeFrent.png");
    arvore = al_load_bitmap("../bitmap/arvore.png");
    telhado = al_load_bitmap("../bitmap/telhado.png");
    mesa = al_load_bitmap("../bitmap/mesa.png");
    mesaDir = al_load_bitmap("../bitmap/mesaDir.png");
    porta = al_load_bitmap("../bitmap/portaFrent.png");
    portaDir = al_load_bitmap("../bitmap/portaDir.png");
    canto = al_load_bitmap("../bitmap/canto.png");


    while(true){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(frame1 > 3){
            frame1 -= 3;
        }

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_D){
            current_frame_x1 = 32 * 2 + 2;
            current_frame_y1 = 32 * 1 + 1;
            inverte = 0;
            frame1 += 0.3f;
            pos_x1 += 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_A){
            current_frame_x1 = 32 * 2 + 2;
            current_frame_y1 = 32 * 1 + 1;
            inverte = 1;
            frame1 += 0.3f;
            pos_x1 -= 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_S){
            current_frame_x1 = 32 * 2 + 2;
            current_frame_y1 = 32 * 0 + 0;
            frame1 += 0.3f;
            pos_y1 += 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_W){
            current_frame_x1 = 32 * 2 + 2;
            current_frame_y1 = 32 * 2 + 2;
            frame1 += 0.3f;
            pos_y1 -= 20;
        }

        if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
            current_frame_y2 = 96 * 2;
            pos_x2 += 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){
            current_frame_y2 = 96 * 1;
            pos_x2 -= 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
            current_frame_y2 = 96 * 0;
            pos_y2 += 20;
        }else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
            current_frame_y2 = 96 * 3;
            pos_y2 -= 20;
        }

        al_clear_to_color(al_map_rgb(255,255,255));
        DesenharMapa();
        al_draw_bitmap_region(person1,current_frame_x1 * (int)frame1,current_frame_y1,32,32,pos_x1,pos_y1,inverte);
        al_draw_bitmap_region(person2,64,current_frame_y2,64,96,pos_x2,pos_y2,0);
        DesenharArvore();

        al_flip_display();

    }

    al_destroy_bitmap(person1);
    al_destroy_bitmap(person2);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    //al_destroy_bitmap(iconePage);


    return 0;
}

