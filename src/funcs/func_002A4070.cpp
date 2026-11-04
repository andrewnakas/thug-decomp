extern char D_00371C78[];
extern char D_00378408[];
extern void* D_0038EB78;

struct Iter_002A4070 {
    int m0;
    int m4;
    void* m8;
    Iter_002A4070() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A4070() { m8 = D_00371C78; }
};

struct Elem_002A4070 {
    char pad[0x1C];
    int m1C;
};

struct Obj_002A4070;
extern "C" int func_001FA648(void* g);
extern "C" Elem_002A4070* func_002A53F8(Obj_002A4070* self, Iter_002A4070* it, int a);
extern "C" Elem_002A4070* func_002A5490(Obj_002A4070* self, Iter_002A4070* it, int a);
extern "C" int func_00202B30(int id);
extern "C" int func_002B1F58(Elem_002A4070* e);
extern "C" int func_002B1FC8(Elem_002A4070* e);
extern "C" int func_002A3EA8(Obj_002A4070* self);
extern "C" void func_002006C8(void* a, int b, int c, int d, int e, char* f, int g, int h, int i);

struct Obj_002A4070 {
    char pad[0x14];
    void* m14;
    void Notify(Elem_002A4070* src);
};

void Obj_002A4070::Notify(Elem_002A4070* src)
{
    Iter_002A4070 it;
    Iter_002A4070* p = &it;
    if (func_001FA648(D_0038EB78) == 1) {
        return;
    }
    for (Elem_002A4070* e = func_002A53F8(this, p, 0); e; e = func_002A5490(this, &it, 0)) {
        if (e == src) continue;
        if (func_00202B30(src->m1C) == 1) continue;
        int ok = 0;
        if (func_002B1F58(e)) ok = 1;
        else if (func_002B1FC8(e)) ok = func_002A3EA8(this);
        if (ok) func_002006C8(m14, src->m1C, 0x7E, 0x4499, func_002B1F58(e), D_00378408, 9, 0, 1);
    }
}
