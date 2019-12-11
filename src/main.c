/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** main.c
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

int my_window(void)
{
    all_t all;
    init_struct(&all.sprite);
    init_window(&all.windows);
    curseur(&all.souris);
    init_music(&all.sound);
    all.clock.animation = sfClock_create();
    sfRenderWindow_setFramerateLimit(all.windows.window, 45);

    while (sfRenderWindow_isOpen(all.windows.window)) {
        sfRenderWindow_clear(all.windows.window, sfBlack);
        while (sfRenderWindow_pollEvent(all.windows.window, &all.event)) {
            analyse_events(all.windows.window, all.event, &all.sprite);
        }
        caller(&all.sprite, &all.windows, &all.clock, &all.souris);
        sfSprite_setTextureRect(all.sprite.bird, all.sprite.rect);
        sfRenderWindow_display(all.windows.window);
    }
    sfRenderWindow_destroy(all.windows.window);
    return (0);
}

int option(char *str)
{
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
        my_putstr("USAGE: \n   You have to kill the ball \
with using your mouse\n   If you fail your clic, \
Momohamed Henni will not be happy\n\n Made by:\n\
   Matisse Page\n");
        return (0);
    }
    return (84);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        option(av[1]);
    } else {
        my_window();
    }
    return 0;
}