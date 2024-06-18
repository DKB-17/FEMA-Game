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
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}
};

void DesenharMapa(){
    for(int i=0;i<HMAPA;i++){
        for(int j=0;j<WMAPA;j++){
            if(mapa[i][j] == 0){
                al_draw_rectangle(BLOCO * j, BLOCO * i,BLOCO * j + BLOCO, BLOCO * i + BLOCO,al_map_rgb(0,0,0),0);
            }else{
                al_draw_rectangle(BLOCO * j, BLOCO * i,BLOCO * j + BLOCO, BLOCO * i + BLOCO,al_map_rgb(255,255,255),0);
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
    al_set_window_position(display, 0,50);
    al_set_window_title(display, "BritoMen");
    //al_set_display_icon(display, iconePage);

    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(1.0/60.0);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    ALLEGRO_BITMAP *mapa = al_load_bitmap("./personagem/map2 - School.png");




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



        /*frame1 += 0.3f;
        if(frame1 > 3){
            frame1 -= 3;
        }
        frame2 += 0.3f;
        if(frame2 > 3){
            frame2 -= 3;
        }
        */

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(mapa,0,0,0);
        al_draw_bitmap_region(person1,current_frame_x1 * (int)frame1,current_frame_y1,32,32,pos_x1,pos_y1,inverte);
        al_draw_bitmap_region(person2,64,current_frame_y2,64,96,pos_x2,pos_y2,0);
        DesenharMapa();

        al_flip_display();

    }

    al_destroy_bitmap(person1);
    al_destroy_bitmap(person2);
    al_destroy_bitmap(mapa);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    //al_destroy_bitmap(iconePage);


    return 0;
}

