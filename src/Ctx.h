#ifndef CTX_H__
#define CTX_H__

#include "Template.h"
#include "App_UI.h"
#include "PN_Manifest.h"
#include "PN_ManifestEle.h"
#include "Common.h"
#include "TM_Tower.h"
#include "E_Input.h"
#include "RP_Cell.h"
#include "S_ID.h"

typedef struct Ctx {
    CtxUI *ctx_UI;

    Template *tpl;

    //
    E_Input *input;

    //
    RP_Cell *rp_cell;

    S_ID *s_id;

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
    ctx->input = input;

    // RP cell
    RP_Cell *rp_cell = (RP_Cell *)calloc(1, sizeof(RP_Cell));
    RP_Cell_Init(rp_cell);
    ctx->rp_cell = rp_cell;

    S_ID *s_id = (S_ID *)calloc(1, sizeof(S_ID));
    S_ID_Init(s_id);
    ctx->s_id = s_id;
}

void ctxfree(Ctx *ctx) {
    Template_free(ctx->tpl);
    free(ctx);
}

#endif