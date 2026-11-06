/* fuzzy: 92.0 */
struct Box_002C2288 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Cell_002C2288 {
    int val;
    int pad[3];
};

struct Req_002C2288 {
    int x;
    int cur;
    int z;
    int flags;
    int kind;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
};

struct Node_002C2288 {
    char pad0[0xC];
    Node_002C2288* mC;
};

struct Piece_002C2288 {
    char pad0[0x8];
    int m8;
    char padC[0x30 - 0xC];
    int m30;
};

struct Owner_002C2288 {
    char pad0[0x18];
    void* m18;
};

extern "C" Piece_002C2288* func_002BC5A0(Node_002C2288* n);
extern "C" void* func_002BAB80(void* p);
extern "C" void func_002C0F90(void* self, Req_002C2288* r);
extern "C" void func_002BE958(void* self, void* p, int f);
extern "C" void func_00133D48(void* p, int v);
extern "C" void func_002C21B8(void* self);

struct Obj_002C2288 {
    Owner_002C2288* m0;
    char pad4[0xC];
    int m10;
    int m14;
    char pad18[0x78 - 0x18];
    int m78;
    char pad7C[4];
    Node_002C2288* m80;
    char pad84[0x352C - 0x84];
    Box_002C2288 m352C;
    Box_002C2288 m3532;
    Cell_002C2288** cells;
    Box_002C2288* Bounds() { return &m352C; }
    Box_002C2288* Box2() { return &m3532; }
    int Fill(int mode, int test);
};

int Obj_002C2288::Fill(int mode, int test)
{
    for (Node_002C2288* n = m80; n; n = n->mC) {
        Piece_002C2288* p = func_002BC5A0(n);
        if ((p->m8 >> 3) & 1) p->m8 |= 0x10;
    }
    Req_002C2288 r;
    r.m1C = mode;
    m78 = 0;
    r.m24 = 0;
    r.m20 = test;
    r.m28 = 0;
    int x;
    for (x = Bounds()->x - 1; x < Bounds()->x + Bounds()->w + 1; x++) {
        for (int z = Bounds()->z - 1; z < Bounds()->z + Bounds()->d + 1; z++) {
            r.z = z;
            r.x = x;
            r.m18 = cells[x][z].val;
            r.m14 = Box2()->y;
            func_002C0F90(this, &r);
        }
    }
    x = 0;
    int sum = 0;
    Node_002C2288* nx;
    for (Node_002C2288* n = m80; n; n = nx) {
        nx = n->mC;
        Piece_002C2288* p = func_002BC5A0(n);
        if (p->m8 & 0x10) {
            sum += p->m30;
            x++;
            if (!test) func_002BE958(this, func_002BAB80(func_002BC5A0(n)), 0);
        }
    }
    x += m10;
    sum += m14;
    func_00133D48(m0->m18, 0);
    if (!test) {
        func_002C21B8(this);
        return 1;
    }
    if (x < r.m24 || sum < r.m28) return 0;
    return 1;
}
