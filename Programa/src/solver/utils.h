//
// Created by jonathan on 22-10-18.
//

#pragma once

#include <stdbool.h>


bool int_array_equal(int *a0, int *a1, int sz);
void int_array_print(int *arr, int sz);
void int_array_println(int *arr, int sz);

int * index_to_xy(int index, int size);
int xy_to_index(int x, int y, int size);
int get_adj_num(int i, int dir, int size);


typedef enum
{
    DJB2,
    SUM,
    ADDITION
} Hash;


unsigned long sum(int *arr, int size, int m);
unsigned long djb2(int *arr, int size, int m);
unsigned long addition_hash(int *arr, int size, int m);
const char * hash_func_to_str(Hash hash);
