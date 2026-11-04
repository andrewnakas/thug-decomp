extern char D_003782B8[];
extern char D_00378260[];
extern char D_003782C8[];
extern char D_003782D8[];
extern char D_003782E8[];
extern char D_003782F8[];
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" int func_001E8A50(void* p, char* key, int* out, int flag);

struct Obj_002A1CE8 {
    char pad[0xBC];
    char mBC[4];
    int GetKind();
};

int Obj_002A1CE8::GetKind()
{
    int r = 4;
    int v;
    func_001E8A50(func_00202EF8(mBC, func_001F0D78(D_003782B8)), D_00378260, &v, 1);
    if (v == func_001F0D78(D_003782C8))
        r = 0;
    else if (v == func_001F0D78(D_003782D8))
        r = 2;
    else if (v == func_001F0D78(D_003782E8))
        r = 3;
    else if (v == func_001F0D78(D_003782F8))
        r = 4;
    return r;
}
