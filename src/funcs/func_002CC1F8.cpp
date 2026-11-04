struct Info_002CC1F8 {
    int m0[9];
    char m24[0x30];
};

struct Item_002CC1F8 {
    char pad0[0x1C];
    char m1C[0x80];
    Info_002CC1F8 m9C;
};

extern char D_00392948[];
extern "C" void func_003331D0(char* buf, char* fmt, ...);

struct Obj_002CC1F8 {
    int m0;
    Item_002CC1F8* m4[32];
    void Refresh();
    void Set(int idx, Info_002CC1F8* info);
};

extern "C" void func_002CC178(Obj_002CC1F8* o);

void Obj_002CC1F8::Set(int idx, Info_002CC1F8* info)
{
    Item_002CC1F8** p = m4;
    p += idx;
    func_003331D0((*p)->m1C, D_00392948, info->m24);
    (*p)->m9C = *info;
    func_002CC178(this);
}
