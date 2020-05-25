#ifndef STATE_H
#define STATE_H

#include "entity.h"

#define PLAYER_HP  100
#define PLAYER_RAD 10
#define PLAYER_SPEED 4
#define PLAYER_COOLDOWN 8
//la vida
#define MINION_HP   50
#define MINION_RAD 12
#define BRUTE_HP   120
#define BRUTE_RAD  16

//metralleta
#define BULLET_DMG 15
#define BULLET_SPEED 16
#define BULLET_RAD   5

//bazuca
#define BALA_DMG 100
#define BALA_SPEED 5
#define BALA_RAD   20

//bolas de fuego
#define LANZA_DMG 10
#define LANZA_SPEED 1
#define LANZA_RAD   12




// ==== PLAYER DEFINITION
typedef struct {
    entity ent;
    // Cooldown of the player's weapon. The player can shoot when it is <=0.
    int cooldown;
} player;

// ==== ENEMY DEFINITION
typedef enum {MINION=0, BRUTE=1} enemykind;

typedef struct {
    entity ent;
    enemykind kind;
} enemy;

// ==== BULLET DEFINTION

typedef struct {
    entity ent;
    // TODO: We may want to add more fields...
} bullet;

typedef struct {
    entity ent;
} bala;
typedef struct {
    entity ent;
} lanza;

// ==== STATE DEFINITION

#define MAX_ENEMIES 128
#define MAX_BULLETS 50
#define MAX_BALAS  1
#define MAX_LANZAS  10

#define N_BUTTONS 8

// A state represents everything that's happening with the game objects at a given time.
typedef struct {
    // The player
    player pla;

    // An array of enemies:
    int n_enemies;
    enemy enemies[MAX_ENEMIES];

    // An array of bullets:
    int n_bullets;
    bullet bullets[MAX_BULLETS];
    //An array of balas
    int n_balas;
    bala balas[MAX_BALAS];
    //An array of bolas de fuego
    int n_lanzas;
    lanza lanzas[MAX_LANZAS];

    // State of the controls, should be updated on each step.
    int button_state[N_BUTTONS];
    float aim_angle;//para apuntar con el mouse

} state;

// Creates an empty state, allocating memory for it.
state *state_new();

// Updates the state of the game to the next frame.
void state_update(level *lvl, state *sta,int xx, int yy,int zz);

// Put enemies at random in the state until it has n_enemies enemies.
void state_populate_random(level *lvl, state *sta, int n_enemies);

// Deletes a state and the memory it requires.
void state_free(state *sta);



#endif
