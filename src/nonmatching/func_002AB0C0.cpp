/* fuzzy: 96.7 */
extern "C" void func_00105260(void* list, void* p);
struct Heap_002AB0C0 {
    char pad0[0xF4];
    int mF4;
};

struct Ent_002AB0C0 {
    char pad0[8];
    int m8;
    char mC[0x58 - 0xC];
    char m58[0x94 - 0x58];
    char* Get58() { return m58; }
};

struct Elem_002AB0C0 {
    char pad[0x14C];
    unsigned int m14C;
    char pad150[0x168 - 0x150];
    void* m168;
};

struct Mgr_002AB0C0 {
    char pad[0xB4];
    void* mB4;
};

extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_001047F8(void* p, int pri);
extern char D_00378D18[];
extern char D_00378C98[];

struct Task_002AB0C0 {
    char base[0x18];
    void* vt;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Task_002AB0C0(int pri) { func_001047F8(this, pri); }
};

struct TaskA_002AB0C0 : Task_002AB0C0 {
    void (*fn)(void*);
    Elem_002AB0C0* m20;
    TaskA_002AB0C0(void (*f)(void*), Elem_002AB0C0* e) : Task_002AB0C0(0) {
        fn = f;
        m20 = e;
        vt = D_00378D18;
    }
};

struct TaskB_002AB0C0 : Task_002AB0C0 {
    char* m1C;
    int m20;
    int m24;
    void (*fn)(void*);
    Mgr_002AB0C0* m2C;
    TaskB_002AB0C0(void (*f)(void*), Mgr_002AB0C0* m) : Task_002AB0C0(-1000) {
        m24 = 0;
        fn = f;
        vt = D_00378C98;
        m2C = m;
    }
};

extern Heap_002AB0C0* D_00388A70;
extern Mgr_002AB0C0* D_00392068;
extern Ent_002AB0C0* D_0038C3C0;
extern char* D_0038C308;
extern char D_00378D18[];
extern char D_00378C98[];
extern "C" void func_0029F780(void*);
extern "C" void func_0029F7D8(void*);
extern "C" Elem_002AB0C0* func_002A56E0(Mgr_002AB0C0* m);
extern "C" int func_002B1FE8(Elem_002AB0C0* e);
extern "C" int func_002B1FF8(Elem_002AB0C0* e);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_001047F8(void* p, int pri);

bool Cmd_002AB0C0()
{
    Mgr_002AB0C0* mgr = D_00392068;
    Ent_002AB0C0* tbl = D_0038C3C0;
    char* g = D_0038C308;
    Elem_002AB0C0* e = func_002A56E0(mgr);
    if (func_002B1FE8(e) || func_002B1FF8(e)) return false;
    func_0010A950(D_00388A70, D_00388A70->mF4);
    TaskA_002AB0C0* a = new TaskA_002AB0C0(func_0029F780, e);
    e->m168 = a;
    func_00105260(g + 8, a);
    TaskB_002AB0C0* b = new TaskB_002AB0C0(func_0029F7D8, mgr);
    mgr->mB4 = b;
    func_00105260(tbl[b->m24].mC, b);
    b->m1C = tbl[b->m24].Get58();
    b->m20 = tbl[b->m24].m8;
    e->m14C |= 0x10000;
    func_0010A9B0(D_00388A70);
    return true;
}
