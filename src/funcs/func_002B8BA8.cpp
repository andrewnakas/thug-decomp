extern char D_0037A088[];
extern char D_0037A0A8[];
extern char D_0037A0C0[];
extern char D_0037A0D8[];
extern char D_0037A0E8[];

struct Vec_002B8BA8 {
    float x;
    float y;
    float z;
    float w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Ent_002B8BA8 {
    unsigned int a;
    unsigned int b;
    int c;
};

struct Arr_002B8BA8 {
    char pad[0xC];
    int mC;
};

struct Elem_002B8BA8 {
    char pad[0x10];
    Vec_002B8BA8 m10;
    int m20;
};

struct Grp_002B8BA8 {
    char m0;
    unsigned char m1;
    char pad2[2];
    int m4;
};

struct Pc_002B8BA8 {
    char pad[0x10];
    unsigned short m10;
};

struct Blk_002B8BA8 {
    char pad[0x28];
    int m28;
    int m2C;
};

struct Node_002B8BA8 {
    char pad[0x8];
    Node_002B8BA8* m8;
};

extern void* D_00388A70;
extern "C" void func_00103F28(void* p);
extern "C" int func_002B73B8(void* p, char* name);
extern "C" void func_002B6668(void* l, int a, int b, int c);
extern "C" void func_001F03D0();
extern "C" Arr_002B8BA8* func_001E55B8(unsigned int id, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002B6580(void* l);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, int* out, int req);
extern "C" Grp_002B8BA8* func_002B6810(void* l);
extern "C" Elem_002B8BA8* func_002B67D0(void* l);
extern "C" void func_002B6290(Grp_002B8BA8* g, Elem_002B8BA8* e);
extern "C" void func_002B6550(void* l, Grp_002B8BA8* g);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" Blk_002B8BA8* func_002B6CF0(Node_002B8BA8* n);
extern "C" int func_002B6320(Pc_002B8BA8* p);
extern "C" int func_002B6E90(Blk_002B8BA8* p);
extern "C" Pc_002B8BA8* func_002B6628(void* l, int a, int i);

struct Obj_002B8BA8 {
    char pad0[0x8];
    Node_002B8BA8* m8;
    char padC[0x2C - 0xC];
    char m2C[0xA4 - 0x2C];
    Ent_002B8BA8* mA4;
    void* mA8;
    int mAC;
    void Build();
};

extern "C" int func_002B8FD8(Obj_002B8BA8* o, Arr_002B8BA8* a, int* i);
extern "C" int func_002B90B8(Obj_002B8BA8* o, Arr_002B8BA8* a, int k, int prev, Vec_002B8BA8* v, int* f, int* g);
extern "C" void func_002B9350(Obj_002B8BA8* o, Arr_002B8BA8* a);

void Obj_002B8BA8::Build()
{
    func_00103F28(D_0037A088);
    int a = func_002B73B8(this, D_0037A0A8);
    func_002B6668(m2C, a, func_002B73B8(this, D_0037A0C0), 1);
    func_001F03D0();
    Arr_002B8BA8* arr = func_001E55B8(0xC472ECC5, 0);
    func_001F0370(D_0037A0D8, 0, 0, 0);
    func_002B6580(m2C);
    mA8 = func_0010A638(D_00388A70, 0x400, 1, 0);
    mAC = 0;
    mA4 = (Ent_002B8BA8*)func_0010A638(D_00388A70, 0x6000, 1, 0);
    Vec_002B8BA8 v;
    int f;
    int g;
    int i;
    i = 0;
    if (arr->mC > 0) do {
        void* s = func_001E9378(arr, i);
        mA4[i].a = 0;
        func_001E8398(s, 0x12B4E660, &mA4[i].a, 0);
        mA4[i].b = 0;
        func_001E8398(s, 0x1A3A966B, &mA4[i].b, 0);
        mA4[i].c = 0;
        func_001E8248(s, 0x2E7D5EE7, &mA4[i].c, 0);
    } while (++i < arr->mC);
    i = 0;
    for (;;) {
        int k = func_002B8FD8(this, arr, &i);
        if (i >= arr->mC) {
            func_00103F28(D_0037A0E8);
            break;
        }
        mAC = 0;
        for (;;) {
            f = 0;
            int r = func_002B90B8(this, arr, k, -1, &v, &f, &g);
            if (r == -1)
                break;
            int c = r;
            Grp_002B8BA8* grp = func_002B6810(m2C);
            grp->m4 = k;
            grp->m1 = f;
            Elem_002B8BA8* e = func_002B67D0(m2C);
            e->m10.Set(v.x, v.y, v.z, 1.0f);
            e->m20 = g;
            func_002B6290(grp, e);
            while ((c = func_002B90B8(this, arr, k, c, &v, &f, &g)) != -1) {
                e = func_002B67D0(m2C);
                e->m10.Set(v.x, v.y, v.z, 1.0f);
                e->m20 = g;
                func_002B6290(grp, e);
            }
            func_002B6550(m2C, grp);
        }
    }
    func_0010A8D8(D_00388A70, mA8);
    func_0010A8D8(D_00388A70, mA4);
    func_002B9350(this, arr);
    for (Node_002B8BA8* n = m8; n; n = n->m8) {
        Blk_002B8BA8* b = func_002B6CF0(n);
        b->m28 = 0;
        b->m2C = 0;
        int j = 0;
        Pc_002B8BA8* p;
        while ((p = func_002B6628(m2C, func_002B6E90(b), j++))) {
            b->m28 += p->m10;
            b->m2C += func_002B6320(p);
        }
    }
}
