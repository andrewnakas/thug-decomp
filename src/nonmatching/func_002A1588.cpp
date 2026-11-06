/* fuzzy: 66.3 */
/* nonmatch func_002A1588: best earlier draft (thug-claude-lane3/work/w53/p7/func_002A1588.fail), 149 of 171 words differ (size 0x2a8, want 0x2ac). */
extern char D_00371C78[];
extern char D_00366B58[];
extern char D_00378218[];
extern char D_00378230[];

struct Iter_002A1588 {
    int m0;
    int m4;
    void* m8;
    Iter_002A1588() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A1588() { m8 = D_00371C78; }
};

struct Iter2_002A1588 {
    int m0;
    int m4;
    void* m8;
    Iter2_002A1588() { m8 = D_00366B58; m4 = 0; }
    ~Iter2_002A1588() { m8 = D_00366B58; }
};

struct Conn_002A1588 {
    char pad0[0x68];
    int m68;
    int Has(const int& f) { return m68 & f; }
};

struct Elem_002A1588 {
    char pad0[0x18];
    int m18;
    Conn_002A1588* m1C;
};

struct Table_002A1588 {
    char pad0[0x18];
    void* m18;
    char pad1C[0x9C - 0x1C];
    int m9C;
};

struct Skate_002A1588 {
    char pad0[0x3B0];
    unsigned int m3B0;
};

extern Skate_002A1588* D_0038FC78;

extern "C" int func_002A1A38(Table_002A1588* t);
extern "C" Elem_002A1588* func_002A53F8(Table_002A1588* self, Iter_002A1588* it, int a);
extern "C" Elem_002A1588* func_002A5490(Table_002A1588* self, Iter_002A1588* it, int a);
extern "C" int func_00202768(Conn_002A1588* c);
extern "C" unsigned int func_002026D0(Conn_002A1588* c);
extern "C" int func_00202808(Conn_002A1588* c);
extern "C" int func_002B1FE8(Elem_002A1588* e);
extern "C" void func_002A5A88(Table_002A1588* t, Elem_002A1588* e, int why);
extern "C" void func_0022CF98(void* p, int v);
extern "C" Conn_002A1588* func_00200EC0(void* m, Iter2_002A1588* it);
extern "C" int func_002A8258(Table_002A1588* t);
extern "C" void func_002A8250(Table_002A1588* t, int v);
extern "C" void func_001048F0(int v);
extern "C" void func_002A58F8(Table_002A1588* t);
extern "C" void func_002A3870(Table_002A1588* t);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002A1588 {
    char pad0[0x20];
    Table_002A1588* m20;
    void Check();
};

void Obj_002A1588::Check()
{
    Iter_002A1588 it;
    Table_002A1588* t = m20;
    Skate_002A1588* sk = D_0038FC78;
    if (func_002A1A38(t)) {
        Elem_002A1588* e = func_002A53F8(t, &it, 1);
        while (e) {
            Elem_002A1588* next = func_002A5490(t, &it, 1);
            int kick = 0;
            if (!func_00202768(e->m1C)) {
                if (e->m1C->Has(1)) {
                    if (func_002026D0(e->m1C) > 20000) {
                        kick = 1;
                    } else if (func_00202808(e->m1C) > 20) {
                        int id = e->m18;
                        int b = func_002B1FE8(e);
                        func_002A5A88(t, e, 5);
                        if (!b) func_0022CF98(sk, id);
                    }
                } else {
                    kick = func_002026D0(e->m1C) > 60000;
                }
                if (kick) {
                    int id = e->m18;
                    int b = func_002B1FE8(e);
                    func_002A5A88(t, e, 1);
                    if (!b) func_0022CF98(sk, id);
                }
            }
            e = next;
        }
    } else {
        Iter2_002A1588 it2;
        if (t->m18) {
            Conn_002A1588* c = func_00200EC0(t->m18, &it2);
            if (!c) return;
            if (func_002A8258(t) == 7 || func_002A8258(t) == 6 || func_002A8258(t) == 5) {
                if (func_002026D0(c) > 20000) {
                    if (sk->m3B0 == 0x9F2BAFB7) {
                        func_001F0370(D_00378218, 0, 0, 0);
                        func_001048F0(t->m9C);
                        func_002A8250(t, 9);
                    } else {
                        func_001F0370(D_00378230, 0, 0, 0);
                        func_002A58F8(t);
                        func_002A3870(t);
                    }
                }
            }
        }
    }
}
