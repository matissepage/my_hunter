/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** sound.c
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

int init_music(sound_t *sound)
{
    sound->music = sfMusic_createFromFile("Sound/stadium.wav");
        if (!sound->music)
            return EXIT_FAILURE;
        sfMusic_play(sound->music);
        return(0);
}

int sound_fail(sound_t *sound)
{
    sound->music = sfMusic_createFromFile("Sound/nul.ogg");
        if (!sound->music)
            return EXIT_FAILURE;
        sfMusic_play(sound->music);
        return(0);
}