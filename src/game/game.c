/*
** EPITECH PROJECT, 2023
** game
** File description:
** game
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "button.h"
#include "interact.h"
#include "menu.h"
#include "player_movement.h"
#include "sprite.h"
#include "game.h"
#include "fight.h"
#include "my.h"

static void init_sprite(game_t *g)
{
    sprite_init(&g->player, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    g->player_textures[0] = g->player.texture;
    g->player_textures[1] =
        sfTexture_createFromFile("resource/player/walk.png", NULL);
    g->player_state = IDLE;
    g->player.animation_speed = 0.28;
    sprite_init(&g->map, "resource/map/map.png",
        (sfIntRect){0, 0, MAP_WIDTH, MAP_HEIGHT});
    sprite_init(&g->interact, "resource/map/interact.png",
        (sfIntRect){0, 0, INTERACT_WIDTH, INTERACT_HEIGHT});
    sfSprite_setScale(g->map.sprite, (sfVector2f){4, 4});
    g->interact.animation_speed = 0.10;
    sfSprite_setScale(g->player.sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(g->player.sprite, (sfVector2f){MAP_WIDTH * 1.87,
    MAP_HEIGHT * 1.75});
}

void game_init(game_t *g)
{
    g->mode.width = WIDTH;
    g->mode.height = HEIGHT;
    g->mode.bitsPerPixel = 32;
    g->window = sfRenderWindow_create(g->mode, "RPG",
    sfResize | sfClose, NULL);
    g->state = MENU;
    sfRenderWindow_setFramerateLimit(g->window, 60);
    init_sprite(g);
    ennemy_init(g);
    create_fight(&g->fight);
    create_menu(&g->menu);
    well(&g->element);
    g->camera = sfView_createFromRect((sfFloatRect){0, 0, WIDTH, HEIGHT});
    g->clock = sfClock_create();
    g->time = sfClock_getElapsedTime(g->clock);
    g->player_live = 120;
    g->opponent_live = 120;
}

static void poll_events(game_t *g)
{
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (g->event.type == sfEvtMouseButtonPressed && g->state == MENU) {
            menu_event(&g->menu, &g->event);
        }
        if (g->event.type == sfEvtMouseMoved && g->state == MENU) {
            menu_event(&g->menu, &g->event);
        }
        if (g->event.type == sfEvtMouseButtonPressed && g->state == FIGHT) {
            fight_event(&g->fight, &g->event);
        }
        if (g->event.type == sfEvtMouseMoved && g->state == FIGHT) {
            fight_event(&g->fight, &g->event);
        }
    }
}

void game_handle_time(game_t *g)
{
    g->last_time = g->time;
    g->time = sfClock_getElapsedTime(g->clock);
    g->delta_time = (g->time.microseconds / 1000000.0)
    - (g->last_time.microseconds / 1000000.0);
}

static void update(game_t *g)
{
    game_handle_time(g);
    game_update_menu(g);
    game_update_map(g);
    game_update_fight(g);
}

static void render(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    game_render_menu(g);
    game_render_map(g);
    game_render_fight(g);
    sfRenderWindow_display(g->window);
}

void game_loop(game_t *g)
{
    while (sfRenderWindow_isOpen(g->window)) {
        // g->state = FIGHT;
        poll_events(g);
        update(g);
        render(g);
    }
}

void game_free(game_t *g)
{
    sfRenderWindow_destroy(g->window);
    sprite_free(&g->map);
    sprite_free(&g->player);
    for (int i = 0; i < 4; i++) {
        sprite_free(g->tab_ennemy[i]);
    }
    destroy_menu(&g->menu);
}
