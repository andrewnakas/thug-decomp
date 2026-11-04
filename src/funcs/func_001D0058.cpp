struct Obj_001D0058;

struct VEntry_001D0058 {
    short m_delta;
    short m_pad;
    int (*m_fn)(...);
};

struct DEntry_001D0058 {
    short m_delta;
    short m_pad;
    void (*m_fn)(void*, int);
};

struct List_001D0058 {
    char m_pad[0x18];
    Obj_001D0058* m_18;
};

struct Obj_001D0058 {
    char m_pad0[0x8];
    int m_8;
    char m_C;
    char m_D;
    char m_padE[0x18 - 0xE];
    Obj_001D0058* m_18;
    void* m_1C;
    VEntry_001D0058* m_vtbl;
};

struct Mgr_001D0058 {
    char m_pad[0xC];
    void* m_C;
    List_001D0058* m_10;
};

extern "C" void* func_001046B0(int size);
extern "C" Obj_001D0058* func_001D0FB0(Obj_001D0058* o);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001E53A0(unsigned int key, int a);
extern "C" void func_001D0DD8(void* p, int* name, Obj_001D0058* o);
extern "C" void func_001D1070(Obj_001D0058* o, int name);
extern VEntry_001D0058 D_00363AD8[];
extern VEntry_001D0058 D_00363CF8[];
extern char D_003639B8[];

struct ObjA_001D0058 : Obj_001D0058 {
    ObjA_001D0058()
    {
        func_001D0FB0(this);
        m_vtbl = D_00363AD8;
    }
};

struct ObjB_001D0058 : Obj_001D0058 {
    ObjB_001D0058()
    {
        func_001D0FB0(this);
        m_vtbl = D_00363CF8;
    }
};

static inline void* operator new(unsigned int size, int)
{
    return func_001046B0(size);
}

extern "C" int func_001D0058(Mgr_001D0058* mgr, int name, int type, int a3, int t0, int t1, int t2)
{
    Obj_001D0058* o = 0;
    switch (type) {
    case 5:
        o = new (0) ObjA_001D0058;
        break;
    case 7:
        o = new (0) ObjB_001D0058;
        break;
    }
    o->m_C = t1;
    o->m_8 = t2;
    o->m_D = 0;
    char buf[0x100];
    func_003331D0(buf, D_003639B8, name);
    VEntry_001D0058* e = &o->m_vtbl[3];
    if (e->m_fn((char*)o + e->m_delta, a3, t0)) {
        if (!func_001E53A0(0x25DC7904, 0) && o) {
            DEntry_001D0058* d = (DEntry_001D0058*)&o->m_vtbl[1];
            d->m_fn((char*)o + d->m_delta, 3);
        }
        return 0;
    }
    int n = name;
    func_001D0DD8(mgr->m_C, &n, o);
    func_001D1070(o, n);
    o->m_1C = mgr->m_10;
    o->m_18 = mgr->m_10->m_18;
    ((Obj_001D0058*)mgr->m_10->m_18)->m_1C = o;
    mgr->m_10->m_18 = o;
    VEntry_001D0058* f = &o->m_vtbl[12];
    return f->m_fn((char*)o + f->m_delta);
}
