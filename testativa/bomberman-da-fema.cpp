#include <iostream>
#include <allegro.h>
#include <allegro_font.h>
#include <allegro_image.h>


using namespace std;

int main(){

    al_init();
    al_init_font_addon();
    al_init_image_addon();

    //ALLEGRO_BITMAP* iconePage = al_load_bitmap("");

    ALLEGRO_DISPLAY *display = al_create_display(1280,720);
    al_set_window_position(display, 0,50);
    al_set_window_title(display, "BritoMen");
    //al_set_display_icon(display, iconePage);

    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(1.0/60.0);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    ALLEGRO_BITMAP *person1 = al_load_bitmap("./personagem/personagem1.png");

    while(true){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(person1,0,0,0);
        al_flip_display();
    }

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    //al_destroy_bitmap(iconePage);


    return 0;
}

