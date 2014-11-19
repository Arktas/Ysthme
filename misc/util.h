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
#include "XMLparser.h"

#include "../resource/Data.h"

#define PI 3.1415

#define PLAYER_SPELL 0
#define MONSTER_SPELL 1

#define XMAX 1366
#define YMAX 768
#define ORIGIN_DIFF_X round(XMAX/2)
#define ORIGIN_DIFF_Y round(YMAX/2)
//Ground states
#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20
#define GRASS 0

//biosphere parameters
#define LIFE_MANAGEMENT_RANGE 5000
#define NB_MONSTER 20
//Spell parameters
#define SPELL_SPEED 45

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



class MainManager;
class UIManager;
class MonsterManager;
class PlayerManager;
class MonsterInterface;
class Data;
#endif // UTIL
