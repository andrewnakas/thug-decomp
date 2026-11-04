extern char D_003783F0[];
extern char D_00378D18[];
extern char D_00378C98[];

struct Pool_002A3CC8 {
    char pad[0xF4];
    int mF4;
};

struct Slot_002A3CC8 {
    int m0;
    int m4;
    char m8[0x54 - 0x8];
    char m54[0x94 - 0x54];
};

struct Mgr_002A3CC8 {
    char pad[0x8];
    char m8[4];
};

extern Pool_002A3CC8* D_00388A70;
struct Slots_002A3CC8 {
    int m0;
    Slot_002A3CC8 s[4];
};
extern Slots_002A3CC8* D_0038C3C0;
extern Mgr_002A3CC8* D_0038C308;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* p, int v);
extern "C" void func_00105260(void* list, void* node);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_0029F780();
extern "C" void func_0029F7D8();

struct Elem_002A3CC8 {
    char pad0[0x18];
    int m18;
    int m1C;
    char pad20[0x168 - 0x20];
    void* m168;
};

extern "C" Elem_002A3CC8* func_002B1BD8(void* p, unsigned int id);
extern "C" int func_002B1FC8(Elem_002A3CC8* e);
extern "C" int func_002B1FE8(Elem_002A3CC8* e);

struct Cb_002A3CC8 {
    char pad[0x18];
    void* vt;
    void* fn;
    void* owner;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb_002A3CC8(void* f, void* o, int pri) { func_001047F8(this, pri); vt = D_00378D18; fn = f; owner = o; }
};

struct Cb2_002A3CC8 {
    char pad[0x18];
    void* vt;
    void* m1C;
    int m20;
    int m24;
    void* fn;
    void* owner;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb2_002A3CC8(void* f, void* o) { func_001047F8(this, -1000); m24 = 0; fn = f; vt = D_00378C98; owner = o; }
};

struct Obj_002A3CC8 {
    char pad0[0xB4];
    Cb2_002A3CC8* mB4;
    char padB8[0x1A8 - 0xB8];
    int m1A8;
    Elem_002A3CC8* Add(int a, int b, unsigned int id);
};

extern "C" Elem_002A3CC8* func_002A49B8(Obj_002A3CC8* o);
extern "C" void func_002A4A58(Obj_002A3CC8* o, Elem_002A3CC8* e);
extern "C" Elem_002A3CC8* func_002A56E0(Obj_002A3CC8* o);

Elem_002A3CC8* Obj_002A3CC8::Add(int a, int b, unsigned int id)
{
    func_0010A950(D_00388A70, D_00388A70->mF4);
    Elem_002A3CC8* e = func_002B1BD8(func_001046B0(0x16C), id);
    e->m18 = a;
    e->m1C = b;
    if (func_002B1FC8(e)) {
        if (func_002B1FE8(e)) {
            Slots_002A3CC8* slots = D_0038C3C0;
            Mgr_002A3CC8* mgr = D_0038C308;
            func_001F0370(D_003783F0, 0, 0, 0);
            func_002A4A58(this, func_002A49B8(this));
            Cb_002A3CC8* cb = new Cb_002A3CC8((void*)func_0029F780, e, 0);
            e->m168 = cb;
            func_00105260(mgr->m8, cb);
            Cb2_002A3CC8* c2 = new Cb2_002A3CC8((void*)func_0029F7D8, this);
            mB4 = c2;
            func_00105260(slots->s[c2->m24].m8, c2);
            c2->m1C = slots->s[c2->m24].m54;
            c2->m20 = slots->s[c2->m24].m4;
        } else {
            m1A8 = 0;
        }
    } else {
        if (func_002B1FE8(func_002A56E0(this)) && !m1A8)
            func_002A4A58(this, e);
    }
    func_0010A9B0(D_00388A70);
    return e;
}
