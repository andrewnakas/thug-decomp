struct Box_002BE6E0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002BE6E0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char rot;
    unsigned char flag;
    char pad[3];
    int m8;
};

struct Src_002BE6E0 {
    char pad[8];
    int m8;
    char padC[0x34 - 0xC];
    int m34;
};

struct Piece_002BE6E0 {
    char pad[8];
    int m8;
    char padC[0x34 - 0xC];
    int m34;
    virtual void V0();
    virtual void V1();
    virtual void Place(void* t, Box_002BE6E0* b, int rot, bool f);
};

struct Node_002BE6E0 {
    char pad[8];
    Piece_002BE6E0* m8;
    Node_002BE6E0* mC;
};

extern void* D_00388A70;
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" Piece_002BE6E0* func_002BB3E0(void* p);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002BC4D0(Src_002BE6E0* s);
extern "C" void func_002BB298(Piece_002BE6E0* p, int n);
extern "C" Item_002BE6E0 func_002BC218(Src_002BE6E0* s, int i);
extern "C" void** func_002C0368();
extern "C" void* func_002B7740(void* a, int b, int c);
extern "C" void* func_002B77E0(void* a, void* b, int c);
extern "C" void func_002B6F30(void* t, int rot, int c);
extern "C" Box_002BE6E0* func_002BAA28(Box_002BE6E0* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002BB818(Piece_002BE6E0* p);
extern "C" Node_002BE6E0* func_002C48E0(unsigned int size);

struct Obj_002BE6E0 {
    void* m0;
    char pad[0x80 - 4];
    Node_002BE6E0* m80;
    int m84;
    int m88;
    Piece_002BE6E0* Create(Src_002BE6E0* src, int flag);
};

Piece_002BE6E0* Obj_002BE6E0::Create(Src_002BE6E0* src, int flag)
{
    void* pool = D_00388A70;
    func_0010A950(pool, func_002B74E0(m0));
    int fl = flag ? 4 : 0;
    Piece_002BE6E0* p = func_002BB3E0(func_0010A638(D_00388A70, 0x3C, 1, 0));
    func_0010A9B0(D_00388A70);
    int n = func_002BC4D0(src);
    func_002BB298(p, n);
    p->m34 = src->m34;
    if (src->m8 >> 3 & 1) {
        p->m8 |= 8;
        fl |= 0x20;
    }
    if (src->m8 >> 10 & 1) {
        p->m8 |= 0x400;
        fl |= 0x100;
    }
    if (src->m8 & 0x4000)
        p->m8 |= 0x4000;
    for (int i = 0; i < n;) {
        Item_002BE6E0 r = func_002BC218(src, i);
        i++;
        void* t = func_002B77E0(m0, func_002B7740(*func_002C0368(), r.m8, 0), fl);
        func_002B6F30(t, r.rot, 0);
        Box_002BE6E0 b;
        func_002BAA28(&b, r.x, r.y, r.z, 0, 0, 0);
        p->Place(t, &b, r.rot, r.flag != 0);
    }
    func_002BB818(p);
    void* pool2 = D_00388A70;
    func_0010A950(pool2, func_002B74E0(m0));
    Node_002BE6E0* nd = func_002C48E0(0x10);
    func_0010A9B0(D_00388A70);
    nd->m8 = p;
    nd->mC = 0;
    if (!m80) {
        m80 = nd;
    } else {
        Node_002BE6E0* q = m80;
        while (q->mC)
            q = q->mC;
        q->mC = nd;
    }
    m88++;
    return p;
}
