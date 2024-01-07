#ifndef ENTITISE_E_INPUT_H__
#define ENTITISE_E_INPUT_H__

#include "Common.h"


typedef struct E_Input {
    Vector2 mousePos; // mouse screen pos
    Vector2 mouseWorldPos;
    bool isMouseDown;
    /* data */
} E_Input;

void E_Input_Process(E_Input* input) {
    input->isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    input->mousePos = GetMousePosition();
}

#endif