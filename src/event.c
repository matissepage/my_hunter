/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** event.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_hunter.h"

void manage_mouse_click(sfMouseButtonEvent event, ballon_t *sprite)
{
    sound_t nul;

    if (event.x >=  sprite->pos.x 
    && event.x <= sprite->pos.x+110 
    && event.y >=  sprite->pos.y 
    && event.y <=  sprite->pos.y+110) {
            sprite->pos.x = -150;
            sprite->pos.y = (int)(rand() % 800);
            my_putstr("hit\n");
            //score.score = score.score + 1;
    } else if (event.x >=  sprite->position_germain.x 
    && event.x <= sprite->position_germain.x+110 
    && event.y >=  sprite->position_germain.y 
    && event.y <=  sprite->position_germain.y+110) {
            sprite->position_germain.x = -300;
            sprite->position_germain.y = (int)(rand() % 1200);
            my_putstr("hit\n");
            //score.score = score.score + 1;
    } else {
        sound_fail(&nul);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, ballon_t *sprite)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, sprite);
}