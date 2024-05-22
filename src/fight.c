/*
** EPITECH PROJECT, 2024
** fight
** File description:
** fight
*/
#include "game.h"
#include "fight.h"

static void set_scale(fight_t *fight)
{
    sfSprite_setScale(fight->platform1.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->platform2.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->player.sprite, (sfVector2f){15, 15});
    sfSprite_setScale(fight->opponent.sprite, (sfVector2f){-15, 15});
    sfSprite_setScale(fight->life.sprite, (sfVector2f){4, 4});
    sfSprite_setScale(fight->life2.sprite, (sfVector2f){4, 4});
    sfSprite_setScale(fight->paper.sprite, (sfVector2f){0.6, 0.6});
    sfSprite_setScale(fight->cisor.sprite, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(fight->rock.sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setScale(fight->skills.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->skills2.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->bar.sprite, (sfVector2f){2.5, 2.5});
}

static void set_position(fight_t *fight)
{
    sfSprite_setPosition(fight->platform1.sprite, (sfVector2f){350, 700});
    sfSprite_setPosition(fight->platform2.sprite, (sfVector2f){1200, 700});
    sfSprite_setPosition(fight->opponent.sprite, (sfVector2f){1670, 420});
    sfSprite_setPosition(fight->player.sprite, (sfVector2f){-30, 20});
    sfSprite_setPosition(fight->life.sprite, (sfVector2f){450, 430});
    sfSprite_setPosition(fight->life2.sprite, (sfVector2f){1300, 430});
    sfSprite_setPosition(fight->rock.sprite, (sfVector2f){860, 860});
    sfSprite_setPosition(fight->paper.sprite, (sfVector2f){980, 860});
    sfSprite_setPosition(fight->cisor.sprite, (sfVector2f){1100, 860});
    sfSprite_setPosition(fight->skills.sprite, (sfVector2f){10, 50});
    sfSprite_setPosition(fight->skills2.sprite, (sfVector2f){1400, 50});
    sfSprite_setPosition(fight->bar.sprite, (sfVector2f){750, 800});
}

static void init_player(fight_t *fight)
{
    sprite_init(&fight->player, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    sprite_init(&fight->opponent, "resource/player/Skeleton.png",
        (sfIntRect){0, 35, 25, 30});
    sprite_init(&fight->platform1, "resource/fight/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->platform2, "resource/fight/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->life, "resource/fight/h3.png",
        (sfIntRect){0, 0, 64, 16});
    sprite_init(&fight->life2, "resource/fight/h3.png",
        (sfIntRect){0, 0, 64, 16});
    sprite_init(&fight->skills, "resource/fight/ui.png",
        (sfIntRect){0, 0, 220, 90});
    sprite_init(&fight->skills2, "resource/fight/ui.png",
        (sfIntRect){0, 0, 220, 90});
}

void create_fight(fight_t *fight)
{
    init_player(fight);
    sprite_init(&fight->scene, "resource/fight/scene1.png",
        (sfIntRect){0, 0, 1920, 1080});
    sprite_init(&fight->bar, "resource/fight/ui.png",
        (sfIntRect){0, 80, 220, 100});
    sprite_init(&fight->rock, "resource/fight/rock.png",
        (sfIntRect){15, 0, 105, 150});
    sprite_init(&fight->paper, "resource/fight/rock.png",
        (sfIntRect){122, 0, 108, 150});
    sprite_init(&fight->cisor, "resource/fight/rock.png",
        (sfIntRect){230, 0, 105, 150});
    fight->player.animation_speed = 0.18;
    fight->opponent.animation_speed = 0.18;
    set_position(fight);
    set_scale(fight);
}
