struct Msg_00233A60 {
    unsigned char m0;
    char pad1[3];
    union {
        int i;
        unsigned short s;
    } m4;
    unsigned int m8;
    int mC[1];
};

struct Ent_00233A60 {
    char pad0[0x30];
    int m30;
};

struct Obj_00233A60 {
    Msg_00233A60* m0;
    char pad4[0x18];
    int m1C;
    int Handle();
};

extern int D_00392068;
extern "C" unsigned int func_002A7660(int g);
extern "C" int func_0022E358(int a);
extern "C" int func_0024F540(int a);
extern "C" Ent_00233A60* func_002A52F0(int g, unsigned short id);
extern "C" int func_0022E048(int a);
extern "C" int func_00265E50(int a, int id, int v);

int Obj_00233A60::Handle()
{
    int g = D_00392068;
    Msg_00233A60* m = m0;
    int o = m1C;
    unsigned int t = func_002A7660(g);
    if (m->m0 != t) return 3;
    int v;
    if (func_0024F540(func_0022E358(o))) v = func_002A52F0(g, m->m4.s)->m30;
    else v = m->m4.i;
    for (unsigned int i = 0; i < m->m8; i++) {
        func_00265E50(func_0022E048(o), m->mC[i], v);
    }
    return 1;
}
