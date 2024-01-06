#ifndef APP_UI_H__
#define APP_UI_H__

#include "PN_Manifest.h"

typedef struct CtxUI {
    PN_Manifest *pn_towerMani;
} CtxUI;

void CtxUIInit(CtxUI *ctxUI) {
    assert(ctxUI != NULL);
}

void App_UI_PanelTower_Open(CtxUI *ctxUI, Vector2 startPos) {
    assert(ctxUI != NULL);
    PlogNoArg("start\r\n");

    PN_Manifest *panel = ctxUI->pn_towerMani;
    if (panel == NULL) {
        panel = (PN_Manifest *)calloc(1, sizeof(PN_Manifest));
        PN_Manifest_Ctor(panel);
        ctxUI->pn_towerMani = panel;
    }
    PN_Manifest_Init(ctxUI->pn_towerMani, startPos);
}

void App_UI_PanelTower_Close() {
}

void App_UI_PanelTower_Toggle() {
}

void App_UI_PanelTower_Draw(CtxUI *ctxUI) {
    assert(ctxUI != NULL);
    if (ctxUI->pn_towerMani != NULL && ctxUI->pn_towerMani->isOpen) {
        PlogNoArg("pn\r\n");
        PN_Manifest_Draw(ctxUI->pn_towerMani);
    }
}
void App_UI_PanelTower_Add(CtxUI *ctxUI, int typeID, Color color) {
    PN_Manifest_AddEle(ctxUI->pn_towerMani, typeID, color);
}
#endif