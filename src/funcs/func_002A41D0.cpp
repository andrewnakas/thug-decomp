extern void* D_0038FC78;
extern char D_00378418[];

struct Node_002A41D0 {
    int m0;
    void* m4;
    int m8;
    Node_002A41D0* mC;
    Node_002A41D0* Valid() { return (int)m4 != -1 ? this : 0; }
};

struct Game_002A41D0 {
    char pad[0x3C];
    Node_002A41D0* m3C;
    int Count() {
        int n = 0;
        for (Node_002A41D0* c = m3C->Valid(); c; c = c->mC->Valid()) n++;
        return n;
    }
};

struct Info_002A41D0 {
    char m0;
    char m1[0x10];
    signed char m11;
    char pad12[2];
    int m14;
    int m18;
    int m1C;
    unsigned int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
};

struct Elem_002A41D0 {
    char pad[0x28];
    int m28;
    int m2C;
    int m30;
    char m34[0x10];
    int m44;
};

struct Ext_002A41D0 {
    char pad[0x1C];
    void* m1C;
    char pad2[0x1298 - 0x20];
    int m1298;
};

struct Obj_002A41D0;
extern "C" int func_00215EE0(int a, int b);
extern "C" void* func_0022E3C8(void* g, int v);
extern "C" int func_002A19A8(Obj_002A41D0* s);
extern "C" int func_0022DD38(void* g);
extern "C" void* func_0022C6E0(void* g, void* a, int b, int c, int d);
extern "C" Ext_002A41D0* func_00185578(void*, unsigned int);
extern "C" Elem_002A41D0* func_002A52F0(Obj_002A41D0* self, unsigned short id);
extern "C" Elem_002A41D0* func_002A56E0(Obj_002A41D0* self);
extern "C" void func_002A47D8(Obj_002A41D0* self, Elem_002A41D0* e);
extern "C" Elem_002A41D0* func_002A3CC8(Obj_002A41D0* self, void* a, int b, int c);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_002A47B8(Obj_002A41D0* self, Elem_002A41D0* e);
extern "C" void func_002B2BC0(Elem_002A41D0* e, int v);
extern "C" int func_002A3EA8(Obj_002A41D0* self);
extern "C" void* func_0022E048(void* p);
extern "C" void func_00266100(void* p);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" int func_002B1FC8(Elem_002A41D0* e);
extern "C" void func_00206968(void* p);
extern "C" void func_00239198(void* p, int v);

struct Obj_002A41D0 {
    void Add(Info_002A41D0* p);
};

void Obj_002A41D0::Add(Info_002A41D0* p)
{
    void* s4 = 0;
    Game_002A41D0* g = (Game_002A41D0*)D_0038FC78;
    if (!(p->m20 & 4)) {
        void* s0;
        if (func_00215EE0(0, 0))
            s0 = func_0022E3C8(g, p->m11);
        else
            s0 = func_0022E3C8(g, 0);
        if (func_002A19A8(this)) {
            if (p->m20 & 1) {
                s4 = func_0022C6E0(g, s0, 1, p->m11, 0);
            } else {
                int n;
                if (func_0022DD38(g))
                    n = g->Count();
                else
                    n = (g->Count() + 1) & 7;
                s4 = func_0022C6E0(g, (void*)p->m1C, 0, p->m11, n);
                if (p->m38)
                    func_00185578(s4, 0x18223FD6)->m1298 = p->m38;
            }
        } else {
            s4 = func_0022C6E0(g, s0, 1, p->m11, g->Count());
        }
    }
    Elem_002A41D0* e = func_002A52F0(this, p->m11);
    if (p->m20 & 0x10) {
        if (!e) {
            e = func_002A56E0(this);
            if (!e) goto add;
        }
        func_002A47D8(this, e);
        e = 0;
    }
    if (!e) {
    add:
        e = func_002A3CC8(this, s4, p->m14, p->m20 & 0x7805);
        func_00331A9C(e->m34, p->m1);
        e->m30 = p->m28;
        e->m28 = p->m2C;
        e->m2C = p->m30;
        e->m44 = p->m38;
        func_002A47B8(this, e);
        if (p->m20 & 0x80)
            func_002B2BC0(e, 1);
    }
    if (p->m20 & 0x10) {
        func_002A3EA8(this);
        func_00266100(func_0022E048(g));
        func_001F0370(D_00378418, 0, 0, 0);
    }
    if (!func_002B1FC8(e)) {
        void* x = func_00185578(s4, 0xD262802F)->m1C;
        func_00206968(s4);
        func_00239198(x, p->m34);
    }
}
