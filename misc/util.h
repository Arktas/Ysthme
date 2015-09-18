#ifndef UTIL
#define UTIL


#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<math.h>
#include<iostream>
#include <list>
#include <string.h>
#include <sstream>
#include <time.h>
#include <unistd.h>


#include "Clock.h"
#include "Hitbox.h"

#include "../resource/Data.h"

#define PI 3.1415

#define PLAYER_SPELL 0
#define MONSTER_SPELL 1

#define XMAX 1366
#define YMAX 768
#define ORIGIN_DIFF_X round(XMAX/2)
#define ORIGIN_DIFF_Y round(YMAX/2)
//Ground states
#define MAP_SIZE_X 100
#define MAP_SIZE_Y 100
#define GRASS 0

//biosphere parameters
#define LIFE_MANAGEMENT_RANGE 5000
#define NB_MONSTER 2
//Spell parameters
#define SPELL_SPEED 30

//Monster parameters

//PLayer states
#define PLAYER_PASSIVE 0
#define PLAYER_CAST 1
#define SPEED 6

#define FPS 60

#define DOWN 0
#define DOWN_LEFT 1
#define LEFT 2
#define UP_LEFT 3
#define UP 4
#define UP_RIGHT 5
#define RIGHT 6
#define DOWN_RIGHT 7

//Hitbox parma define

#define _H_ENVIRONMENT 0
#define _H_ENVIRONMENT_T 1
#define _H_MONSTER 2
#define _H_CHARACTER 3
#define _H_PLAYER 4
#define _H_PROJECTILE_PLAYER 5
#define _H_PROJECTILE_MONSTER 6
#define _H_ITEM 7

#define _H_WALL 0
#define _H_NOTHING 1
#define _H_DROP 2
#define _H_HIT 3

//Inventory paramters
#define INVENTORY_H 5
#define INVENTORY_L 10
#define INVENTORY_SIZE 50
#define ITEM_MAX_STACK 100
#define INVENTORY_SLOT_SIZE 68
#define STACK_NUMBER_DECAL_L 45
#define STACK_NUMBER_DECAL_H 45


#define SHOW_HITBOX 0 //debug hitbox


class MainManager;
class UIManager;
class MonsterManager;
class PlayerManager;
class MonsterInterface;
class Data;

typedef struct{
    bool left;
    bool right;
    bool top;
    bool down;
    bool dirTop;
    bool dirDown;
    bool dirRight;
    bool dirLeft;
    bool spell;
    bool mousePressed;
    bool interfaceON;
    bool inventoryShowed;
    bool updateInventoryInterface;
    bool drop;
    bool moovingItem;
}_MANAGER_Flags;

#endif // UTIL
