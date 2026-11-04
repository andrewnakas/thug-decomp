struct Msg_00233808 {
    unsigned char m0;
    signed char m1;
};

struct Player_00233808 {
    char pad0[0x18];
    int m18;
};

struct Obj_00233808 {
    Msg_00233808* m0;
    char pad4[0x18];
    int m1C;
    int Handle();
};

extern int D_00392068;
extern "C" Player_00233808* func_002A52F0(int g, unsigned short id);
extern "C" int func_002A5588(int g, unsigned short id);
extern "C" void func_002A5628(int g, int c);
extern "C" void func_002A5A88(int g, Player_00233808* p, int v);
extern "C" void func_0022CF98(int a, int b);
extern "C" void func_002A8598(int g);

int Obj_00233808::Handle()
{
    Msg_00233808* m = m0;
    int g = D_00392068;
    int o = m1C;
    Player_00233808* p = func_002A52F0(g, (signed char)m->m0);
    if (p) {
        int id = p->m18;
        func_002A5A88(g, p, m->m1);
        func_0022CF98(o, id);
    } else {
        int c = func_002A5588(g, (signed char)m->m0);
        if (c) func_002A5628(g, c);
    }
    func_002A8598(g);
    return 1;
}
