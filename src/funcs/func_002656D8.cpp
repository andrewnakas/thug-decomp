extern char D_00375F18[];
extern void* D_00392068;
extern int D_0038FC78;

struct Ctx_002656D8 {
    int index;
    int found;
    char m_pad[0x208];
};

extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_001E6B30(void* p);
extern "C" bool func_002A1A38(void* p);
extern "C" void func_00265678(void* item, Ctx_002656D8* ctx);
extern "C" void func_002668B0(void* list, void (*cb)(void*, Ctx_002656D8*), Ctx_002656D8* ctx);
extern "C" void func_002313E0(int id, int a);

struct Obj_002656D8;
extern "C" void func_00265EF0(Obj_002656D8* self, int index);

struct Obj_002656D8 {
    int m0;
    int m4;
    char m8[0x30];
    void* m38;
    bool Select(int index);
};

bool Obj_002656D8::Select(int index)
{
    void* s = D_00392068;
    func_00103F28(D_00375F18);
    func_001E6B30(m38);
    if (func_002A1A38(s)) {
        Ctx_002656D8 ctx;
        ctx.index = index;
        ctx.found = 0;
        func_002668B0(m8, func_00265678, &ctx);
        if (!ctx.found)
            return false;
        func_002313E0(D_0038FC78, 0);
    }
    func_00265EF0(this, index + 1);
    return true;
}
