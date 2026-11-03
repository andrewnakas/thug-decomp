extern char D_003714C0[];

struct Iter_002AD240 {
    int m0;
    int m4;
    void* m8;
    Iter_002AD240() { m4 = 0; m8 = D_003714C0; }
    ~Iter_002AD240() { m8 = D_003714C0; }
};

struct Elem_002AD240 {
    char pad[0x11];
    signed char m11;
    char pad12[0x20 - 0x12];
    int m20;
};

extern "C" Elem_002AD240* func_002A5820(void* s);
extern "C" void func_002B2BC0(Elem_002AD240* p, int v);
extern "C" Elem_002AD240* func_002A52F0(void* s, unsigned short id);
extern "C" Elem_002AD240* func_002A5520(void* s, Iter_002AD240* it);
extern "C" Elem_002AD240* func_002A5558(void* s, Iter_002AD240* it);

struct Obj_002AD240 {
    signed char* m0;
    char pad[0x18];
    void* m1C;
};

bool Cmd_002AD240(Obj_002AD240* o)
{
    void* mgr = o->m1C;
    signed char* p = o->m0;
    Elem_002AD240* e = func_002A5820(mgr);
    if (e) {
        func_002B2BC0(e, 0);
    } else {
        Iter_002AD240 it;
        for (Elem_002AD240* x = func_002A5520(mgr, &it); x; x = func_002A5558(mgr, &it)) {
            if (x->m20 & 0x80) {
                x->m20 &= ~0x80;
                break;
            }
        }
    }
    Elem_002AD240* f = func_002A52F0(mgr, *p);
    if (f) {
        func_002B2BC0(f, 1);
    } else {
        Iter_002AD240 it;
        for (Elem_002AD240* x = func_002A5520(mgr, &it); x; x = func_002A5558(mgr, &it)) {
            if (x->m11 == *p) {
                x->m20 |= 0x80;
                break;
            }
        }
    }
    return true;
}
