struct Box_002C9C18 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void SetSize(unsigned char nw, unsigned char nh, unsigned char nd) { w = nw; h = nh; d = nd; }
};

struct Def_002C9C18 {
    int m0;
    int m4;
    int m8;
    bool F11() { return (m8 & 0x800) != 0; }
    bool F15() { return (m8 & 0x8000) != 0; }
    bool F16() { return (m8 & 0x10000) != 0; }
};

struct Inst_002C9C18 {
    Box_002C9C18 m0;
    char pad6[2];
    int m8;
};

struct Park_002C9C18;

struct Ref_002C9C18 {
    int m0;
    Park_002C9C18* m4;
};

extern "C" Def_002C9C18* func_002BE5F0(Park_002C9C18* b, int key, int* out);
extern "C" Inst_002C9C18* func_002BE6E0(Park_002C9C18* b, Def_002C9C18* p, int a);
extern "C" void func_002BE958(void* self, Inst_002C9C18* p, int f);
extern "C" void func_002C86F0(void* self);
extern "C" void func_002C9DA8(void* self, int v);
extern "C" void func_002C0E60(Park_002C9C18* p, int a, int b);

struct Cursor_002C9C18 {
    int m0;
    Ref_002C9C18 m4;
    char padC[4];
    Box_002C9C18 m10;
    char pad16[0x44 - 0x16];
    int m44;
    char pad48[0x50 - 0x48];
    Inst_002C9C18* m50;
    Ref_002C9C18* GetRef() { return &m4; }
    void SetPiece(int id);
};

void Cursor_002C9C18::SetPiece(int id)
{
    if (m50) {
        m50->m8 &= ~0x200;
        func_002BE958(m4.m4, m50, 0);
        m50 = 0;
    }
    Def_002C9C18* p = func_002BE5F0(GetRef()->m4, id, 0);
    if (p->F16()) {
        m10.SetSize(1, 1, 1);
    } else {
        m50 = func_002BE6E0(GetRef()->m4, p, 1);
        m50->m8 |= 0x200;
        Inst_002C9C18* n = m50;
        Box_002C9C18* b = &m10;
        b->SetSize(n->m0.w, n->m0.h, n->m0.d);
        if (m44 & 1) b->SetSize(b->d, b->h, b->w);
    }
    func_002C86F0(this);
    if (p->F11()) {
        func_002C9DA8(this, 2);
    } else if (p->F15()) {
        func_002C9DA8(this, 4);
        func_002C0E60(GetRef()->m4, 0, 0);
    } else if (p->F16()) {
        func_002C9DA8(this, 6);
        func_002C0E60(GetRef()->m4, 0, 0);
    } else {
        func_002C9DA8(this, 1);
        func_002C0E60(GetRef()->m4, 0, 0);
    }
}
