#ifndef CTX_H__
#define CTX_H__

#include "Template.h"
#include "App_UI.h"
#include "PN_Manifest.h"
#include "PN_ManifestEle.h"
#include "Common.h"
#include "TM_Tower.h"

typedef struct Ctx {
    CtxUI *ctx_UI;

    Template *tpl;

    
} Ctx;

void ctx_Inti(Ctx *ctx) {
    // template
    Template *tpl = (Template *)calloc(1, sizeof(Template));
    Template_Tower_Init(tpl);
    ctx->tpl = tpl;

    CtxUI *ctx_UI = (CtxUI *)calloc(1, sizeof(CtxUI));
    ctx->ctx_UI = ctx_UI;
}

void ctxfree(Ctx *ctx) {
    Template_free(ctx->tpl);
    free(ctx);
}

#endif