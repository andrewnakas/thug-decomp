struct Ent_002636E8 {
    int m0;
    int m4;
    int m8;
    char padC[0x14];
};

struct Obj_002636E8 {
    Ent_002636E8 a[21];
    Ent_002636E8 b[21];
    Ent_002636E8 c[2];
    char pad580[0x5C4 - 0x580];
    int m5C4;
    int Reset(int flag);
};

extern int D_00452ED0[21];
extern "C" void* func_002637B0(Obj_002636E8* o, unsigned int i);
extern "C" void func_0026D5D0(void* p);

int Obj_002636E8::Reset(int flag)
{
    for (unsigned int i = 0; i < 21; i++) {
        a[i].m4 = 0;
        b[i].m4 = 0;
        a[i].m8 = 0;
        b[i].m8 = 0;
        D_00452ED0[i] = 0;
    }
    c[0].m4 = 0;
    c[1].m4 = 0;
    c[0].m8 = 0;
    c[1].m8 = 0;
    m5C4 = 0;
    if (flag) {
        for (unsigned int j = 0; j < 21; j++) func_0026D5D0(func_002637B0(this, j));
    }
    return 1;
}
