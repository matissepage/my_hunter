/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu.c
*/

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

void init_menu(menu_t *start_menu)
{
    start_menu->position.x = 0;
    start_menu->position.y = 0;

    start_menu->menu_texture = sfTexture_createFromFile("Images/start_menu5", NULL);
    start_menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(start_menu->menu_sprite, start_menu->menu_texture, sfTrue);
}