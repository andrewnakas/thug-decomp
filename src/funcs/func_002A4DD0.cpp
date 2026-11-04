extern char D_00371C78[];
extern char D_00378480[];
extern char D_00392130[];
extern char D_00392138[];
extern char D_00378490[];
extern char D_003784A0[];
extern char D_00378D18[];
extern char D_00378C98[];
extern char D_003784C8[];
extern char D_003783F0[];

extern "C" void func_0029F780();
extern "C" void func_0029F7D8();

struct Iter_002A4DD0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A4DD0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A4DD0() { m8 = D_00371C78; }
};

struct Elem_002A4DD0;

struct Task_002A4DD0 {
    char pad[0x18];
    void* m18;
    void (*m1C)();
    Elem_002A4DD0* m20;
};

struct Slot_002A4DD0 {
    int m0;
    int m4;
    char m8[0x54 - 0x8];
    char m54[0x94 - 0x54];
};

struct Slots_002A4DD0 {
    int m0;
    Slot_002A4DD0 s[4];
};

struct Obj_002A4DD0;

struct Task2_002A4DD0 {
    char pad[0x18];
    void* m18;
    char* m1C;
    int m20;
    int m24;
    void (*m28)();
    Obj_002A4DD0* m2C;
};

struct Elem_002A4DD0 {
    char pad[0x18];
    int m18;
    char pad1C[0x14C - 0x1C];
    int m14C;
    char pad150[0x168 - 0x150];
    Task_002A4DD0* m168;
};

struct Obj_002A4DD0 {
    char pad[0x74];
    void* m74;
    char pad78[0xB4 - 0x78];
    Task2_002A4DD0* mB4;
    void Start();
};

struct Pool_002A4DD0 {
    char pad[0x148];
    int m148;
};

extern void* D_0038FC78;
extern char* D_0038C308;
extern Slots_002A4DD0* D_0038C3C0;
extern Pool_002A4DD0* D_00388A70;
extern "C" Elem_002A4DD0* func_002A56E0(Obj_002A4DD0* o);
extern "C" int func_002B1FE8(void* item);
extern "C" int func_002A1A38(void* s);
extern "C" void func_002A5A88(void* s, Elem_002A4DD0* e, int v);
extern "C" int func_002B2F30(void* item);
extern "C" void func_002B2BC0(void* p, int v);
extern "C" void func_00268100(void* p);
extern "C" int func_002B22B8(void* item);
extern "C" int func_002B22C8(void* item);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001F0D78(char* s);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_002B2310(void* item);
extern "C" void func_0022CF98(void* p, int v);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002A49B8(void* p);
extern "C" void func_002A4A58(void* p, int v);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* p, int v);
extern "C" void func_00105260(void* p, void* q);
extern "C" void func_002A8260(void* p, int v);

static inline Task_002A4DD0* MakeT_002A4DD0(void* mem, void (*f)(), Elem_002A4DD0* e)
{
    Task_002A4DD0* t = (Task_002A4DD0*)mem;
    func_001047F8(t, 0);
    t->m18 = D_00378D18;
    t->m1C = f;
    t->m20 = e;
    return t;
}

static inline Task2_002A4DD0* MakeT2_002A4DD0(void* mem, void (*f)(), Obj_002A4DD0* o)
{
    Task2_002A4DD0* t = (Task2_002A4DD0*)mem;
    func_001047F8(t, -1);
    t->m18 = D_00378C98;
    t->m24 = 0;
    t->m28 = f;
    t->m2C = o;
    return t;
}

void Obj_002A4DD0::Start()
{
    Iter_002A4DD0 it;
    Slots_002A4DD0* g3;
    void* g = D_0038FC78;
    char* g2 = D_0038C308;
    g3 = D_0038C3C0;
    Elem_002A4DD0* cur = func_002A56E0(this);
    if (func_002B1FE8(cur))
        return;
    if (func_002A1A38(this))
        func_002A5A88(this, cur, 2);
    if (func_002B2F30(cur)) {
        func_002B2BC0(cur, 0);
        if (m74)
            func_00268100(m74);
    }
    if (func_002B22B8(cur)) {
        char buf[64];
        int n = func_002B22C8(cur);
        func_003331D0(buf, D_00378480, n + 1);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7268(s, D_00392130, n);
        func_001E7A30(s, func_001F0D78(D_00392138), 3, func_001E54B8(buf, 0));
        func_001F0370(D_00378490, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
        func_001F0370(D_003784A0, 0, 0, 0);
        func_002B2310(cur);
    }
    cur->m14C |= 4;
    func_0022CF98(g, cur->m18);
    cur->m18 = 0;
    func_0010A950(D_00388A70, D_00388A70->m148);
    func_002A4A58(this, func_002A49B8(this));
    Task_002A4DD0* t = MakeT_002A4DD0(func_001046B0(0x24), func_0029F780, cur);
    cur->m168 = t;
    func_00105260(g2 + 8, t);
    Task2_002A4DD0* t2 = MakeT2_002A4DD0(func_001046B0(0x30), func_0029F7D8, this);
    mB4 = t2;
    func_00105260(g3->s[t2->m24].m8, t2);
    t2->m1C = g3->s[t2->m24].m54;
    t2->m20 = g3->s[t2->m24].m4;
    func_002A8260(this, 0);
    func_001F0370(D_003784C8, 0, 0, 0);
    func_001F0370(D_003783F0, 0, 0, 0);
    func_0010A9B0(D_00388A70);
}
