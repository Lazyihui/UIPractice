#ifndef PN_MANIFEST_H__
#define PN_MANIFEST_H__

#include "Common.h"
#include "PN_ManifestEle.h"

typedef struct PN_Manifest {
    Vector2 startPos;
    float gapY;
    PN_ManifestEle element[100];
    int eleCount;
    bool isOpen;
} PN_Manifest;

void PN_Manifest_Ctor(PN_Manifest *panel) {
    assert(panel != NULL);
    PlogNoArg("a");
    panel->gapY = std_cell;
}

void PN_Manifest_Init(PN_Manifest *panel, Vector2 startPos) {

    assert(panel != NULL);
    panel->startPos = startPos;
    panel->eleCount = 0;
    panel->isOpen = true;
}

void PN_Manifest_AddEle(PN_Manifest *panel, int typeID, Color color) {
    int count = panel->eleCount;
    PN_ManifestEle ele = PN_ManifestEle_Creat(count, typeID, color);
    panel->element[count++] = ele;
    panel->eleCount = count;
}

void PN_Manifest_Close(PN_Manifest *panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

void PN_Manifest_Draw(PN_Manifest *panel) {
    assert(panel != 0);
    if (!panel->isOpen) {
        return;
    } else {
        Vector2 startPos = panel->startPos;
        DrawRectangleV(Vector2_New(startPos.x - 1, startPos.y - 1),
                       Vector2_New(std_cell * 3 + 4, panel->eleCount * (panel->gapY + std_cell * 3) + 4), BLACK);
        for (int i = 0; i < panel->eleCount; i++) {
            PN_ManifestEle *ele = &panel->element[i];
            Rectangle eleRect =
                RectangleNew(startPos.x, startPos.y + (panel->gapY + std_cell * 3) * i, std_cell * 3, std_cell * 3);
            ele->rect = eleRect;
            PN_ManifestEle_Draw(ele);
        }
    }
}

#endif