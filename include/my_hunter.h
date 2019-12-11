/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_hunter.h"
#include <stdio.h>

typedef struct ballon_s
{
    sfTexture* texture;
    sfSprite* bird;
    sfTexture* background_texture;
    sfSprite* background;
    sfTexture* germain;
    sfSprite* germain_sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f position_germain;
    int *test;
}ballon_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
}window_t;

typedef struct event_s
{
    sfEvent event;
    sfMouseButtonEvent press;
    sfVector2f pos;
}event_t;

typedef struct sound_s 
{
    sfMusic* music;
}sound_t;

typedef struct cursor_s
{
    sfTexture* texture;
    sfSprite* cursor;
}cursor_t;

typedef struct menu_s
{
    sfTexture* menu_texture;
    sfSprite* menu_sprite;
    sfVector2f position;
}menu_t;

typedef struct score_s
{
    int score;
}score_t;

typedef struct my_clock_s
{
    sfClock *animation;
    sfTime time;
    float second;
}my_clock_t;

typedef struct all_s
{
    sfEvent event;
    ballon_t sprite;
    window_t windows;
    sound_t sound;
    cursor_t souris;
    my_clock_t clock;
}all_t;

void init_struct(ballon_t *bird);
void init_window(window_t *window);
void manage_mouse_click(sfMouseButtonEvent event, ballon_t *sprite);
void analyse_events(sfRenderWindow *window, sfEvent event, ballon_t *sprite);
void kill(event_t *kill, ballon_t *bird);
int init_music(sound_t *sound);
void curseur(cursor_t *target);
void deplacement(ballon_t *sprite, window_t *windows);
void replace_cursor(cursor_t *target, window_t *windows);
void draw_sprite(window_t *windows, ballon_t *sprite, cursor_t *souris);
void move_rect(ballon_t *move, int offset, int max);
int sound_fail(sound_t *sound);
void anim(ballon_t *sprite);
void set_menu(window_t *windows, menu_t *menu);
int kick_off(sfMouseButtonEvent clic);
void clock_fonction(ballon_t *sprite, window_t *windows, my_clock_t *clock);
void caller(ballon_t *sprite, window_t *windows, my_clock_t *clock, cursor_t *souris);
int my_menu(void);

#endif /*MY_H*/