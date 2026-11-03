extern char D_00392888[];
extern char D_00392890[];
extern char D_0037AD18[];

struct Mgr_002CAA80 {
    char pad[0xAC];
    unsigned int mAC;
};
extern Mgr_002CAA80* D_00392808;
extern "C" int func_001E87B8(void* params, char* name);

extern "C" bool func_002CAA80(void* params)
{
    Mgr_002CAA80* m = D_00392808;
    if (func_001E87B8(params, D_00392888)) return m->mAC == 0x7ECA21E5;
    if (func_001E87B8(params, D_00392890)) return m->mAC == 0xA40F0B8A;
    if (func_001E87B8(params, D_0037AD18)) return m->mAC != 0xD443A2BC;
    return false;
}
