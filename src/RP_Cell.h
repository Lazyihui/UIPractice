#ifndef RP_CELL_H__
#define RP_CELL_H__

#include <stdio.h>
#include <stdlib.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "common.h"
#include "E_Cell.h"

typedef struct RP_Cell {
    // 分开看一个是数组 一个是指针
    E_Cell **all;
    int count;
} RP_Cell;

void RP_Cell_Init(RP_Cell *rp) {
    rp->all = (E_Cell **)calloc(20, sizeof(E_Cell *));
    rp->count = 0;
}

void RP_Cell_Free(RP_Cell *rp) {
    for (int i = 0; i < rp->count; i++) {
        free(rp->all[i]);
    }
    free(rp->all);
    free(rp);
}

void RP_Cell_Add(RP_Cell *rp, E_Cell *cell) {
    rp->all[rp->count++] = cell;
}

// 移除
void RP_Cell_Remove(RP_Cell *rp, E_Cell *cell) {
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i]->ID == cell->ID) {
            rp->all[i] = rp->all[rp->count];
            rp->count--;
            return;
        }
    }
}

// 找到是哪一个cell
E_Cell *RP_Cell_Get(RP_Cell *rp, int ID) {
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i]->ID == ID) {
            return rp->all[i];
        }
    }
    return NULL;
}
#endif