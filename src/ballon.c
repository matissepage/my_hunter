/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** bird.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_hunter.h"


void init_struct(ballon_t *ball)
{
    ball->rect.top = 0;
    ball->rect.left = 0;
    ball->rect.width = 110;
    ball->rect.height = 110;
    ball->pos.x = 0;
    ball->pos.y = 0;
    ball->position_germain.x = -700;
    ball->position_germain.y = 750;
    ball->background_texture = sfTexture_createFromFile("Images/fond.jpg", NULL);
    ball->background = sfSprite_create();
    sfSprite_setTexture(ball->background, ball->background_texture, sfTrue);
    ball->texture = sfTexture_createFromFile("Images/ballon.png", NULL);
    ball->bird = sfSprite_create();
    sfSprite_setTexture(ball->bird, ball->texture, sfTrue);
    sfSprite_setTextureRect(ball->bird, ball->rect);
    ball->germain = sfTexture_createFromFile("Images/nul_germain.png", NULL);
    ball->germain_sprite = sfSprite_create();
    sfSprite_setTexture(ball->germain_sprite, ball->germain, sfTrue);
}

void deplacement(ballon_t *sprite, window_t *windows)
{
    sprite->pos.x = sprite->pos.x + 15;
        if (sprite->pos.x >= windows->video_mode.width) {
            sprite->pos.x = -150;
            sprite->pos.y = rand() % 1100;
        }
        if (sprite->pos.y >= 1100) {
            sprite->pos.y = rand() % 1100;
        }
    sprite->position_germain.x = sprite->position_germain.x + 15;
        if (sprite->position_germain.x >= windows->video_mode.width) {
            sprite->position_germain.x = -150;
            sprite->position_germain.y = rand() % 1100;
        }
        if (sprite->position_germain.y >= 1200) {
            sprite->position_germain.y = rand() % 1200;
        }
}

void draw_sprite(window_t *windows, ballon_t *sprite, cursor_t *souris)
{
    sfRenderWindow_drawSprite(windows->window, sprite->background, NULL);
    sfSprite_setPosition(sprite->bird, sprite->pos);
    sfSprite_setPosition(sprite->germain_sprite, sprite->position_germain);
    sfRenderWindow_drawSprite(windows->window, sprite->bird, NULL);
    sfRenderWindow_drawSprite(windows->window, souris->cursor, NULL);
    sfRenderWindow_drawSprite(windows->window, sprite->germain_sprite, NULL);
}

void clock_fonction(ballon_t *sprite, window_t *windows, my_clock_t *clock)
{
    clock->time = sfClock_getElapsedTime(clock->animation);
    clock->second = clock->time.microseconds / 1000.0;
    if (clock->second > 2) {
        sprite->rect.left += 110;
        if (sprite->rect.left >= 990) {
            sprite->rect.left = 0;
        }
        sfClock_restart(clock->animation);
        }
}

void caller(ballon_t *sprite, window_t *windows, my_clock_t *clock, cursor_t *souris)
{
    clock_fonction(sprite, windows, clock);
    deplacement(sprite, windows);
    replace_cursor(souris, windows);
    draw_sprite(windows, sprite, souris);
}