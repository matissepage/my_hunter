/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** window.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_hunter.h"

void init_window(window_t *windows)
{
    windows->video_mode.width = 1200;
    windows->video_mode.height = 900;
    windows->video_mode.bitsPerPixel = 60;

    windows->window = sfRenderWindow_create(windows->video_mode, "KILL THE BALL", sfDefaultStyle, NULL);
}

/*void set_menu(window_t *windows, menu_t *menu)
{
    menu->menu_texture = sfTexture_createFromFile("Images/start_menu4.png", NULL);
    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, menu->menu_texture, sfTrue);
    sfRenderWindow_drawSprite(windows->window, menu->menu_sprite, NULL);
}*/