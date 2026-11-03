struct Obj_002CCEF8;
struct Box_002CCEF8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void Set(unsigned char a, signed char b, unsigned char c) { x = a; y = b; z = c; }
    unsigned char GetX() const { return x; }
    unsigned char GetZ() const { return z; }
};

struct List_002CCEF8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Node_002CCEF8 {
    char pad0[0xC];
    Node_002CCEF8* mC;
};

struct Piece_002CCEF8 {
    char pad0[0x8];
    int m8;
};

extern "C" void func_002BAA28(Box_002CCEF8* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002CC970(Obj_002CCEF8* o, Box_002CCEF8* c, int a, int b, int d);
extern "C" void* func_002C0368();
extern "C" void* func_002BF948(void* self, Box_002CCEF8* b);
extern "C" List_002CCEF8* func_002BC630(List_002CCEF8* l, void* r);
extern "C" void func_002BC640(List_002CCEF8* l, int f);
extern "C" Node_002CCEF8* func_002BC690(List_002CCEF8* l);
extern "C" void* func_002BC5A0(Node_002CCEF8* n);
extern "C" Piece_002CCEF8* func_002BAB80(void* p);
extern "C" void func_002BB700(Piece_002CCEF8* p, void* arg, int c);

struct Obj_002CCEF8 {
    void Apply(unsigned char a, unsigned char b, int d, void* arg);
};

void Obj_002CCEF8::Apply(unsigned char a, unsigned char b, int d, void* arg)
{
    Box_002CCEF8 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    func_002CC970(this, &c, a, b, d);
    c.Set(c.GetX(), 0, c.GetZ());
    List_002CCEF8 l;
    void* t = func_002C0368();
    Box_002CCEF8 c2 = c;
    func_002BC630(&l, func_002BF948(t, &c2));
    if (!l.m0) {
        func_002BC640(&l, 2);
        return;
    }
    for (Node_002CCEF8* n = func_002BC690(&l); n; n = n->mC) {
        Piece_002CCEF8* p = func_002BAB80(func_002BC5A0(n));
        if (((p->m8 >> 3) & 1) == 0) func_002BB700(p, arg, 0);
    }
    func_002BC640(&l, 2);
}
