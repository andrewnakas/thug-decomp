extern char D_00375F70[];

struct Obj_00266458;

struct Ctx_00266458 {
    unsigned int index;
    int count;
    unsigned char* buf;
    Obj_00266458* self;
};

extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_002662B0(void* item, Ctx_00266458* ctx);
extern "C" void func_002668B0(void* list, void (*cb)(void*, Ctx_00266458*), Ctx_00266458* ctx);

struct Obj_00266458 {
    int m0;
    int m4;
    char m8[4];
    int Fill(unsigned char* buf);
};

int Obj_00266458::Fill(unsigned char* buf)
{
    Ctx_00266458 ctx;
    ctx.buf = buf;
    ctx.self = this;
    ctx.count = 0;
    for (unsigned int i = 0; i < 8; i++) {
        ctx.buf[i] = 0;
        ctx.index = i;
        func_002668B0(m8, func_002662B0, &ctx);
        func_00103F28(D_00375F70, ctx.buf[i]);
    }
    return ctx.count + 8;
}
