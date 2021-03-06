//
// Created by jonathan on 23-10-18.
//

#pragma once

#include <stdbool.h>
#include "utils.h"


// a record has
// [ size, s_1, s_2, ..., s_size, x, y, g_cost, h_cost, is_visited ]
// size: number of components that make up the state
// x, y: transformation from the empty tile to current state, direction is not needed since you can work this out by
//       looking at the position of the empty tile in current state
// g_cost: number of moves to transform the initial state to current state
// h_cost: heuristic number of moves to transform the current state to final state, needs to be a lower bound of actual
//         number of moves
// is_visited: if this state is in the closed or open set


typedef enum
{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
} Direction;


int compute_h_cost(int size, int *record);
int * create_record(int size, int *state);

void set_state(int *state, int *record);
void set_x(int x, int *record);
void set_y(int y, int *record);
void set_g_cost(int g, int *record);
void set_h_cost(int h, int *record);
void set_visited(bool visited, int *record);

int * get_state(int *record);
int get_state_size(int *record);
int get_x(int *record);
int get_y(int *record);
int get_g_cost(int *record);
int get_h_cost(int *record);
int get_f_cost(int *record);
bool is_visited(int *record);
int * record_get_parent(int *record, int size);
unsigned long hash(int *record, Hash hash, int m);

int get_empty_space_index(int *record);
void move_tile(int from, int to, int *record);
void shift_tile(int x, int y, int *record, int size);
int * get_neighbor(int *record, int size, int *empty_xy, Direction dir);
int ** get_neighbor_states(int *record, int size);

int * record_copy(int *record);
bool record_state_equal(int *r0, int *r1);
bool record_state_ordered(int *record);
void record_print(int *record);
void board_print(int *record, int size);
void state_print(int *state, int size);

void assert_is_neighbor(int *r0, int *r1, int size);
