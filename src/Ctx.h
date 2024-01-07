#ifndef CTX_H__
#define CTX_H__

#include "Template.h"
#include "App_UI.h"
#include "PN_Manifest.h"
#include "PN_ManifestEle.h"
#include "Common.h"
#include "TM_Tower.h"
#include "E_Input.h"

typedef struct Ctx {
    CtxUI *ctx_UI;

    Template *tpl;

    //
    E_Input *input;
} Ctx;

void ctx_Inti(Ctx *ctx) {
    // template
    Template *tpl = (Template *)calloc(1, sizeof(Template));
    Template_Tower_Init(tpl);
    ctx->tpl = tpl;

    CtxUI *ctx_UI = (CtxUI *)calloc(1, sizeof(CtxUI));
    ctx->ctx_UI = ctx_UI;

    E_Input *input = (E_Input *)calloc(1, sizeof(E_Input));
    E_Input_Process(input);
    ctx->input=input;
}

void ctxfree(Ctx *ctx) {
    Template_free(ctx->tpl);
    free(ctx);
}

#endif