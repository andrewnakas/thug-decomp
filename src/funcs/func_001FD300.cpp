struct Obj_001FD300 {
    char pad0[0x20B4];
    char m20B4[0x30];
    unsigned int m20E4;
    unsigned int m20E8;
};

struct Ctx_001FD300 {
    unsigned int* m0;
    char pad4[0xC];
    unsigned int* m10;
    Obj_001FD300* m14;
};

extern unsigned int D_0038EC64;
extern "C" bool func_00202768(Obj_001FD300* obj);
extern "C" void func_001FE388(void* p, unsigned int n);

int func_001FD300(Ctx_001FD300* ctx)
{
    Obj_001FD300* obj = ctx->m14;
    unsigned int* start = ctx->m0;
    if (func_00202768(obj)) {
        return 1;
    }
    unsigned int end = *ctx->m10;
    unsigned int cur = *start;
    if (cur == obj->m20E4) {
        obj->m20E8 = cur;
        unsigned int lim = D_0038EC64;
        unsigned int n = end - *start;
        if (lim < n) n = lim;
        func_001FE388(obj->m20B4, n);
    }
    return 1;
}
