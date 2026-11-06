/* fuzzy: 94.3 */
/* nonmatch func_002C0BE0 (8 of 140 words differ): improved from 29 (w53/p1 draft). Compare written as tmp.x == t->m0[i].GetX() && ... GetY()/GetZ() (inline accessors give the game's three copies of the entry pointer). Left: func_002BB700 arg setup order (a1/a2), ~0x1000 mask in $t1 vs $a2, two post-loop reload regs. Note: the empty for (k < 2) loop reproduces a 2-pass empty count-down loop in the game prologue (likely an array/debug loop); reviewer may question it. 002BC630/002BC640 are List ctor/dtor (called explicitly, as in merged func_002C0640). */
struct Box_002C0BE0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetZ() const { return z; }
    bool Same(const Box_002C0BE0& o) const
    {
        return x == o.x && y == o.y && z == o.z;
    }
};

struct List_002C0BE0 {
    int* m0;
    int m4;
    int m8;
};

struct Node_002C0BE0 {
    char pad0[0xC];
    Node_002C0BE0* mC;
};

struct Piece_002C0BE0 {
    Box_002C0BE0 m0;
    char pad[2];
    int m8;
};

struct H_002C0BE0 {
    Piece_002C0BE0* p;

};

struct Thing_002C0BE0 {
    Box_002C0BE0 m0[12];
    int m48;
    int m4C;
    int m50;
};

extern "C" void* func_002BF5C0(void* b, Box_002C0BE0* box, int a, int c, int d);
extern "C" List_002C0BE0* func_002BC630(List_002C0BE0* l, void* r);
extern "C" void func_002BC640(List_002C0BE0* l, int f);
extern "C" Node_002C0BE0* func_002BC690(List_002C0BE0* l);
extern "C" void func_002BC698(List_002C0BE0* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Piece_002C0BE0* func_002BAB80(void* p);
extern "C" void func_002BB700(void* p, void* arg, int c);
extern "C" int func_002CC318(void* p, Piece_002C0BE0* a, int* out);
extern "C" void func_002CC370(void* p, int a, int b);
extern "C" int func_001E53A0(unsigned int a, int b);

struct Obj_002C0BE0 {
    char pad[0x6B00];
    void* m6B00;
    void Build(Thing_002C0BE0* t);
};

void Obj_002C0BE0::Build(Thing_002C0BE0* t)
{
    H_002C0BE0 arr[2];
    int out;
    for (int k = 0; k < 2; k++) {}
    for (int i = 0; i < t->m48; i++) {
        Box_002C0BE0* b = &t->m0[i];
        List_002C0BE0 l;
        Box_002C0BE0 tmp = *b;
        func_002BC630(&l, func_002BF5C0(this, &tmp, 0, 0, 0));
        if (l.m0[3])
            func_002BC698(&l);
        for (Node_002C0BE0* n = func_002BC690(&l); n; n = n->mC) {
            Piece_002C0BE0* p = func_002BAB80(func_002BC5A0(n));
            arr[i].p = p;
            tmp = p->m0;
            if (tmp.x == t->m0[i].GetX() && tmp.y == t->m0[i].GetY() && tmp.z == t->m0[i].GetZ())
                break;
        }
        func_002BB700(arr[i].p, 0, 0);
        arr[i].p->m8 &= ~0x1000;
        func_002BC640(&l, 2);
    }
    if (func_002CC318(m6B00, arr[0].p, &out))
        func_002CC370(m6B00, out, 1);
    t->m4C = -1;
    t->m50 = func_001E53A0(0x9A27E74D, 0);
}
