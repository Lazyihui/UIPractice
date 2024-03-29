#ifndef TMTOWER_H__
#define TMTOWER_H__

#include "Common.h"

typedef struct TM_Tower {

    int typeID;

    // Logic
    int hp;
    int bulletTypeID;

    // UI
    Color iconColor;
    
    // Draw
    Color worldColor;
    ShapeType shapeType;
    Vector2 size;

} TM_Tower;

TM_Tower TM_Tower_Create(int typeID, int hp, int bulletTypeID, Color iconColor, Color worldColor, ShapeType shapeType, Vector2 size) {
    TM_Tower tm;
    tm.typeID = typeID;
    tm.hp = hp;
    tm.bulletTypeID = bulletTypeID;
    tm.iconColor = iconColor;
    tm.worldColor = worldColor;
    tm.shapeType = shapeType;
    tm.size = size;
    return tm;
}

#endif