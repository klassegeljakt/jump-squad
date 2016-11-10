/******************************************************************************
*     File Name           :     block.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:12]                            *
*     Last Modified       :     [2016-11-10 23:26]                            *
*     Description         :     Block in map.                                 *
******************************************************************************/
#ifndef BLOCK_H
#define BLOCK_H
/*****************************************************************************/
#include "../obj.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/map.h"
/*****************************************************************************/
typedef int (*block_collision_f)(unit_t *player, block_t *self, map_t *map);
typedef int (*spawn_f)(int, int, map_t*);
/*****************************************************************************/
struct block_s {
    obj_t;
    block_collision_f ctop;
    block_collision_f cside;
    block_collision_f cbot;
    char has_collision;
    char ch;
    void *special;
};
/*****************************************************************************/
int block_collision(unit_t *player, map_t *map);
int draw_block(block_t *block);
int cblock(unit_t *player, block_t *self, map_t *map);
/*---------------------------------------------------------------------------*/
int new_brick_block(int y, int x, map_t *map);
int new_normal_block(int y, int x, int ch, map_t *map);
int new_empty_block(int y, int x, map_t *map);
int new_coin_block(int y, int x, map_t *map);
int new_spawner_block(int y, int x, spawn_f spawn, map_t *map);
/*****************************************************************************/
#endif // BLOCK_H