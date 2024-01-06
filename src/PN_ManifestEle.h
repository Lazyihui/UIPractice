#ifndef PN_MANIFESTELE_H__
#define PN_MANIFESTELE_H__

#include "Common.h"

typedef struct PN_ManifestEle {
    int typeID;
    int index;
    Rectangle rect;
    Color color;
} PN_ManifestEle;

PN_ManifestEle PN_ManifestEle_Creat(int index, int typeID, Color color) {
    PN_ManifestEle ele = (PN_ManifestEle){0};
    ele.color = color;
    ele.index = index;
    ele.typeID = typeID;
    return ele;
}

void PN_ManifestEle_Draw(PN_ManifestEle *ele) {
    DrawRectangleRec(ele->rect, ele->color);
}
#endif