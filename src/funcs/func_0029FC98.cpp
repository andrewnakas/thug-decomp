struct Obj_0029FC98_S {
    char pad0[0x94];
    void* m94;
    char pad98[0x4];
    void* m9C;
    char padA0[0x158 - 0xA0];
    int m158;
};

struct Obj_0029FC98_E {
    char pad0[0x20];
    unsigned int m20;
};

struct Iter_0029FC98 {
    int m0;
    int m4;
    Iter_0029FC98() : m4(0) {}
    virtual ~Iter_0029FC98() {}
    virtual void Key();
};

struct Obj_0029FC98 {
    char pad0[0x20];
    Obj_0029FC98_S* m20;
    void Update();
};

extern char D_00377E20[];
extern char D_00377E38[];
extern char D_00377E50[];
extern char D_00377E70[];
extern char D_00377E88[];
extern char D_00377EA0[];
extern char D_00392098[];
extern void* D_0038FC78;

extern "C" int func_002A8258(Obj_0029FC98_S* s);
extern "C" void func_002A8250(Obj_0029FC98_S* s, int v);
extern "C" void* func_002A39E0(Obj_0029FC98_S* s, int v);
extern "C" int func_00201288(void* p);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001048F0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" Obj_0029FC98_E* func_002A5520(Obj_0029FC98_S* s, Iter_0029FC98* it);
extern "C" Obj_0029FC98_E* func_002A5558(Obj_0029FC98_S* s, Iter_0029FC98* it);
extern "C" int func_0022DD38(void* p);
extern "C" void func_0022CF98(void* p, int v);
extern "C" void func_002A4A58(Obj_0029FC98_S* s, int v);

void Obj_0029FC98::Update()
{
    Obj_0029FC98_S* s = m20;
    switch (func_002A8258(s)) {
    case 0:
        break;
    case 1:
        func_001F0370(D_00377E20, 0, 0, 0);
        func_002A8250(s, 0);
        break;
    case 2:
        if (func_00201288(func_002A39E0(s, 0)) == 0) {
            func_001F0370(D_00377E38, 0, 0, 0);
        }
        func_002A8250(s, 0);
        break;
    case 3:
        func_001F0370(D_00377E50, 0, 0, 0);
        func_002A8250(s, 4);
        break;
    case 8: {
        void* p = func_001E6978(func_001190D0(8));
        func_001E73C8(p, D_00392098, s->m158);
        func_001048F0(s->m9C);
        func_001F0370(D_00377E70, p, 0, 0);
        if (p) {
            func_001E6AE8(p, 3);
        }
        break;
    }
    case 4:
        break;
    case 5: {
        Iter_0029FC98 it;
        Obj_0029FC98_E* e;
        for (e = func_002A5520(s, &it); e; e = func_002A5558(s, &it)) {
            if (e->m20 & 1) {
                if (e->m20 & 4) {
                    void* q = D_0038FC78;
                    func_0022CF98(q, func_0022DD38(q));
                    func_002A4A58(s, 0);
                }
                break;
            }
        }
        func_001F0370(D_00377E88, 0, 0, 0);
        func_002A8250(s, 6);
        break;
    }
    case 6:
        break;
    case 7:
        func_001F0370(D_00377EA0, 0, 0, 0);
        func_001048F0(s->m94);
    case 9:
        func_001048F0(s->m9C);
        break;
    }
}
