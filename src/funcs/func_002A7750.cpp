extern char D_00378260[];
extern char D_003920C8[];
extern char D_003920D0[];
extern char D_003920D8[];
extern char D_003920E0[];
extern char D_003920E8[];

extern "C" void* func_00202EF8(void* p, unsigned int name);
extern "C" int func_001E8A50(void* s, char* name, int* out, int f);
extern "C" int func_001F0D78(char* s);

struct Obj_002A7750 {
    char pad[0xBC];
    char mBC[4];
    int GetMode();
};

int Obj_002A7750::GetMode()
{
    int v;
    func_001E8A50(func_00202EF8(mBC, 0xCE238F5D), D_00378260, &v, 1);
    if (v == func_001F0D78(D_003920C8)) return 1;
    if (v == func_001F0D78(D_003920D0)) return 2;
    if (v == func_001F0D78(D_003920D8)) return 3;
    if (v == func_001F0D78(D_003920E0)) return 4;
    if (v == func_001F0D78(D_003920E8)) return 5;
    return 3;
}
