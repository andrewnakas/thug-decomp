extern char D_00378270[];
extern char D_00378260[];
extern char D_003920D0[];
extern char D_003920D8[];
extern char D_003920E0[];
extern char D_003920E8[];
extern char D_003920F0[];
extern char D_003920F8[];
extern char D_00392100[];
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" int func_001E8A50(void* p, char* key, int* out, int flag);

struct Obj_002A1B30 {
    char pad[0xBC];
    char mBC[4];
    int GetLevel();
};

int Obj_002A1B30::GetLevel()
{
    int r = 2;
    int v;
    func_001E8A50(func_00202EF8(mBC, func_001F0D78(D_00378270)), D_00378260, &v, 1);
    if (v == func_001F0D78(D_003920D0))
        r = 2;
    else if (v == func_001F0D78(D_003920D8))
        r = 3;
    else if (v == func_001F0D78(D_003920E0))
        r = 4;
    else if (v == func_001F0D78(D_003920E8))
        r = 5;
    else if (v == func_001F0D78(D_003920F0))
        r = 6;
    else if (v == func_001F0D78(D_003920F8))
        r = 7;
    else if (v == func_001F0D78(D_00392100))
        r = 8;
    return r;
}
