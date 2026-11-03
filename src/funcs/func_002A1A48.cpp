extern char D_00378250[];
extern char D_00378260[];
extern char D_003920C8[];
extern char D_003920D0[];
extern char D_003920D8[];
extern char D_003920E0[];
extern char D_003920E8[];
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" int func_001E8A50(void* p, char* key, int* out, int flag);

struct Obj_002A1A48 {
    char pad[0xBC];
    char mBC[4];
    int GetMode();
};

int Obj_002A1A48::GetMode()
{
    int v;
    func_001E8A50(func_00202EF8(mBC, func_001F0D78(D_00378250)), D_00378260, &v, 1);
    if (v == func_001F0D78(D_003920C8))
        return 0;
    if (v == func_001F0D78(D_003920D0))
        return 1;
    if (v == func_001F0D78(D_003920D8))
        return 2;
    if (v == func_001F0D78(D_003920E0))
        return 3;
    if (v == func_001F0D78(D_003920E8))
        return 4;
    return 2;
}
