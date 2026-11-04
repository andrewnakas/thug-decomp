struct Box_002BE958 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    int GetH() const { return h; }
    unsigned char H() const { return h; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002BE958 {
    int m0;
    int m4;
    int m8;
};

struct Piece_002BE958 {
    Box_002BE958 box;
    char pad6[2];
    int m8;
    char padC[0x30 - 0xC];
    unsigned int m30;
    int m34;
    bool Bit(int n) const { return (m8 >> n) & 1; }
    bool Set(int n) const { if ((m8 >> n) & 1) return true; return false; }
    virtual void A();
    virtual ~Piece_002BE958();
};

extern "C" void* func_002C95E0(int a);
extern "C" void func_002C7B90(void* a, Piece_002BE958* p);
extern "C" void func_002C0E10(void* self, Piece_002BE958* p);
extern "C" void func_002BEFC8(void* self, int id);
extern "C" char* func_002BAA48(Box_002BE958* b, int idx);
extern "C" void func_002BAA50(Box_002BE958* b);
extern "C" unsigned int func_002BEE08(void* self, Box_002BE958* b, int n);
extern "C" void func_002C1600(void* self, Piece_002BE958* p, int v);
extern "C" void func_002C2740(void* self, Piece_002BE958* p);
extern "C" void func_002C2588(void* self, Piece_002BE958* p, void* q);
extern "C" void* func_002C3270(void* self, int id);
extern "C" void func_002BA710(void* a, Piece_002BE958* p, void* r);
extern "C" Item_002BE958* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_002B6CF8(int id);
extern "C" void func_002B7968(void* a, void* b);

struct Obj_002BE958 {
    void* m0;
    char pad4[0x80 - 0x4];
    char m80[8];
    int m88;
    char pad8C[0x6A64 - 0x8C];
    int m6A64;
    void Remove(Piece_002BE958* p, int flags);
};

void Obj_002BE958::Remove(Piece_002BE958* p, int flags)
{
    if (p->m8 & 0x200) return;
    if (func_002C95E0(0)) func_002C7B90(func_002C95E0(1), p);
    func_002C0E10(this, p);
    if (!p->Bit(8) && p->Bit(2)) {
        func_002BEFC8(this, p->m34);
        if (!p->Bit(3)) m6A64 &= ~5;
    }
    if (!p->Set(3) && (flags & 1)) {
        Box_002BE958 b = p->box;
        *func_002BAA48(&b, 1) = b.GetY() + b.GetH();
        func_002BAA50(&b);
        Box_002BE958 b2 = b;
        func_002BEE08(this, &b2, 3);
    }
    func_002C1600(this, p, 0);
    func_002C2740(this, p);
    func_002C2588(this, p, m80);
    void* r = func_002C3270(this, p->m34);
    if (r) func_002BA710(m0, p, r);
    for (unsigned int i = 0; i < p->m30; i++) {
        func_002B7968(m0, func_002B6CF8(func_002BB3B0(p, i)->m8));
    }
    delete p;
    m88--;
}
