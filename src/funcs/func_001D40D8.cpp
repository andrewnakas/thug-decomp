typedef int qword __attribute__((mode(TI)));

union Vec_001D40D8 {
    qword q;
    struct {
        float x, y, z, w;
    } v;
};

struct Box_001D40D8 {
    Vec_001D40D8 mn;
    Vec_001D40D8 mx;
};

struct Item_001D40D8 {
    char m_pad0[0x10];
    Vec_001D40D8 m_10;
    Vec_001D40D8 m_20;
    char m_pad1[0x40 - 0x30];
};

struct VEntry_001D40D8 {
    short m_delta;
    short m_pad;
    void (*m_fn)(void*, int);
};

struct Obj_001D40D8 {
    char m_pad0[0xC];
    VEntry_001D40D8* m_vtbl;
    char m_pad1[0xB0 - 0x10];
    Vec_001D40D8 m_B0;
    Vec_001D40D8 m_C0;
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" Obj_001D40D8* func_001D5180(void* mem);
extern "C" Obj_001D40D8* func_001D6708(void* mem, Item_001D40D8* item);
extern "C" Obj_001D40D8* func_001D4298(void* mem);
extern "C" void func_001D4418(Obj_001D40D8* group, Obj_001D40D8* child);
extern "C" void func_001022D8(Box_001D40D8* box);
extern "C" void func_00102358(Box_001D40D8* box, Vec_001D40D8* p);
extern "C" void func_001DAEF0(Obj_001D40D8* o, int arg);

extern "C" Obj_001D40D8* func_001D40D8(int type, Item_001D40D8* items, int count, int arg)
{
    Obj_001D40D8* o;
    switch (type) {
    case 1: {
        Obj_001D40D8* p = func_001D5180(func_0010A638(D_00388A70, 0xE0, 1, 0));
        if (count > 0) {
            Box_001D40D8 box;
            func_001022D8(&box);
            for (int i = 0; i < count; i++) {
                func_00102358(&box, &items[i].m_10);
                func_00102358(&box, &items[i].m_20);
            }
            p->m_B0 = box.mn;
            p->m_C0 = box.mx;
        }
        o = p;
        break;
    }
    case 4:
        if (count == 1) {
            o = func_001D6708(func_0010A638(D_00388A70, 0xE0, 1, 0), items);
        } else if (count < 2) {
            o = 0;
        } else {
            Obj_001D40D8* g = func_001D4298(func_0010A638(D_00388A70, 0x50, 1, 0));
            for (int i = 0; i < count; i++) {
                func_001D4418(g, func_001D6708(func_0010A638(D_00388A70, 0xE0, 1, 0), &items[i]));
            }
            o = g;
        }
        break;
    default:
        o = 0;
        break;
    }
    if (o) {
        VEntry_001D40D8* e = &o->m_vtbl[12];
        e->m_fn((char*)o + e->m_delta, arg);
        func_001DAEF0(o, arg);
    }
    return o;
}
