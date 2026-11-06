/* fuzzy: 87.8 */
struct Node_002B8018 {
    char pad0[0xC];
    Node_002B8018* mC;
};

struct Elem_002B8018 {
    char pad0[0x14];
    int* m14;
    char pad18[8];
    char m20[0x10];
    int m30;
};

struct Piece_002B8018 {
    char pad0[8];
    int m8;
    char padC[0x38 - 0xC];
    virtual void* Get(int i);
};

struct Pool_002B8018 {
    char pad0[0xD8];
    int mD8;
    char padDC[0xE4 - 0xDC];
    int mE4;
};

struct Ctl_002B8018 {
    char pad0[0x3B0];
    unsigned int m3B0;
};

extern Pool_002B8018* D_00388A70;
extern Ctl_002B8018* D_0038FC78;
extern char D_00379FE0[];
extern char D_00379FF8[];

struct Obj_002B8018;
extern "C" void func_002B7FE8(Obj_002B8018* o);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_002B73B8(Obj_002B8018* o, char* name);
extern "C" void func_002B6668(void* m, void* a, void* b, int c);
extern "C" void* func_002BC5A0(Node_002B8018* n);
extern "C" Piece_002B8018* func_002BAB80(void* p);
extern "C" int func_002BB428(Piece_002B8018* p);
extern "C" Elem_002B8018* func_002B6CF8(void* p);
extern "C" void* func_002B6628(void* t, int key, int j);
extern "C" void* func_002B6810(void* m);
extern "C" int func_002B6EE0(Elem_002B8018* e);
extern "C" void func_002B6368(void* a, void* v, void* pos, int f, int g);
extern "C" void func_002B6550(void* m, void* a);

struct Obj_002B8018 {
    char pad0[0x2C];
    char m2C[0x64 - 0x2C];
    char m64[4];
    void Build(Node_002B8018* list);
};

void Obj_002B8018::Build(Node_002B8018* list)
{
    func_002B7FE8(this);
    if (D_0038FC78->m3B0 == 0xE8B4B836)
        func_0010A950(D_00388A70, D_00388A70->mE4);
    else
        func_0010A950(D_00388A70, D_00388A70->mD8);
    void* a = func_002B73B8(this, D_00379FE0);
    func_002B6668(m64, a, func_002B73B8(this, D_00379FF8), 0);
    func_0010A9B0(D_00388A70);
    for (Node_002B8018* n = list; n; n = n->mC) {
        Piece_002B8018* p = func_002BAB80(func_002BC5A0(n));
        if ((p->m8 >> 2) & 1) {
            if ((p->m8 >> 10) & 1)
                continue;
            int cnt = func_002BB428(p);
            for (int i = 0; i < cnt; i++) {
                Elem_002B8018* e = func_002B6CF8(p->Get(i));
                int j = 0;
                void* v;
                while ((v = func_002B6628(m2C, *e->m14, j++)) != 0) {
                    void* s = func_002B6810(m64);
                    int g = func_002B6EE0(e);
                    func_002B6368(s, v, e->m20, e->m30, ((p->m8 >> 3) & 1) ? 0 : g);
                    func_002B6550(m64, s);
                }
            }
        }
    }
}
