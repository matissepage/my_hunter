/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** cursor.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_hunter.h"

void curseur(cursor_t *target)
{
    target->texture = sfTexture_createFromFile("Images/shoes_1.png", NULL);
    target->cursor = sfSprite_create();
    sfSprite_setTexture(target->cursor, target->texture, sfTrue);
}

void replace_cursor(cursor_t *target, window_t *windows)
{
    sfVector2i position_curseur;
    sfVector2f position_curseur_2f;

    sfRenderWindow_setMouseCursorVisible(windows->window, sfFalse);
    position_curseur = sfMouse_getPositionRenderWindow(windows->window);
    position_curseur_2f.x = position_curseur.x - 75;
    position_curseur_2f.y = position_curseur.y - 62;
    sfSprite_setPosition(target->cursor, position_curseur_2f);
}

/*int kick_off(sfMouseButtonEvent clic)
{
    int kick_off_button_left = 74;
    int kick_off_button_right = 412;
    int kick_off_button_up = 623;
    int kick_off_button_down = 727;

    if (clic.x >=  kick_off_button_left && clic.x <= kick_off_button_right && clic.y >=  kick_off_button_down && clic.y <=  kick_off_button_up)
        return (1);
    return (0);
}*/