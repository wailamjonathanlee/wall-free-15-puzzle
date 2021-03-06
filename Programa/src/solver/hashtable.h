//
// Created by jonathan on 10/20/18.
//

#pragma once

#include <stdbool.h>
#include "utils.h"

typedef struct node Node;
typedef struct hashtable HashTable;

// const int INIT_SIZE = 2 << 5;
// const double LOAD_FACTOR = 0.75;


struct node
{
    Node *prev;
    Node *next;
    int *item;
};


struct hashtable
{
    int max;
    int n_slots;
    int size;
    double load_factor;
    // list of node pointers
    Node **nodes;
    Node *empty;
    int *slot_counter;

    unsigned long(*hash)(int *, int);
};


Node * init_node(int *item);
HashTable * init_hashtable(int max, int n_slots, double load, unsigned long(*hash)(int *, int));

void node_destroy(Node *node, bool destroy_item);
void hashtable_destroy(HashTable *table_p, bool destroy_item);

void hashtable_insert(int *item, HashTable **table_pp);
bool hashtable_contains(int *item, HashTable *table_p, bool(*compar)(int *, int *));
Node * hashtable_get(int *item, HashTable *table_p, bool(*compar)(int *, int *));
void hashtable_delete(int *item, HashTable *table_p, bool(*compar)(int *, int *));
void hashtable_print(HashTable *table_p);

void hashtable_assert(HashTable *table_p);
