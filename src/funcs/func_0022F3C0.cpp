struct Mgr_0022F3C0 {
    char pad0[0x3AC];
    unsigned int m3AC;
};

extern int D_00392068;
extern Mgr_0022F3C0* D_0038FC78;
extern char D_0038FCD0[];
extern char D_00372D88[];
extern "C" int func_001E8A30(void* params, unsigned int id, unsigned int* v, int f);
extern "C" int func_001E7C80(void* params, unsigned int id, char** v, int f);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" unsigned int func_002A76F0(int g);
extern "C" void func_002A7650(int g, unsigned int v);

bool func_0022F3C0(void* params, void* script)
{
    char buf[0x80];
    unsigned int level;
    char* name;
    int g = D_00392068;
    Mgr_0022F3C0* mgr = D_0038FC78;
    if (!func_001E8A30(params, 0, &level, 0)) {
        if (func_001E7C80(params, 0, &name, 1)) {
            func_003331D0(buf, D_0038FCD0, name);
            level = func_001F0D78(buf);
        }
    }
    if (level == func_001F0D78(D_00372D88)) {
        level = func_002A76F0(g);
        func_002A7650(g, level);
    }
    mgr->m3AC = level;
    return true;
}
