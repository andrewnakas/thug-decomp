struct Vec_002BF008 {
    float x;
    float y;
    float z;
};

struct Pos_002BF008 {
    unsigned char x;
    signed char y;
    unsigned char z;
};

struct Box_002BF008 {
    Pos_002BF008 p;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Model_002BF008;

struct Piece_002BF008 {
    Pos_002BF008 m0;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    char pad6[2];
    int m8;
    int mC;
    char pad10[0x30 - 0x10];
    unsigned int m30;
    int m34;
    virtual void* GetModel(unsigned int i);
    void SetPos(unsigned char x, signed char y, unsigned char z) { m0.x = x; m0.y = y; m0.z = z; }
    bool IsLocked() { return (m8 & 0x100) != 0; }
    bool IsHidden() { return (m8 & 8) != 0; }
};

struct Inst_002BF008 {
    char pad[0x30];
    int m30;
};

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;
extern "C" void func_002BB010(Vec_002BF008* out, Piece_002BF008* self, unsigned int i);
extern "C" Inst_002BF008* func_002B6CF8(void* n);
extern "C" void func_002B6EE8(Inst_002BF008* n, Vec_002BF008* v, int f);
extern "C" void func_002B6F30(Inst_002BF008* n, int rot, int f);
extern "C" void func_002B7940(void* p, Inst_002BF008* n);
extern "C" void func_002B8608(void* p, Inst_002BF008* n);

struct Park_002BF008;
extern "C" void func_002C1600(Park_002BF008* p, Piece_002BF008* pc, int f);
extern "C" void func_002C2618(Park_002BF008* p, Piece_002BF008* pc);
extern "C" int func_002C3270(Park_002BF008* p, int id);
extern "C" void func_002BA418(void* p, Vec_002BF008* v, int rot, Box_002BF008* pos, int r, int a, int b);
extern "C" void func_002BEF88(Park_002BF008* p, int id);

struct Park_002BF008 {
    void* m0;
    char pad4[0x6A64 - 4];
    int m6A64;
    void Place(Box_002BF008* pos, Piece_002BF008* p);
};

void Park_002BF008::Place(Box_002BF008* pos, Piece_002BF008* p)
{
    unsigned int i = 0;
    p->m8 |= 4;
    float w = p->m3 * 0.5f;
    float d = p->m5 * 0.5f;
    p->SetPos(pos->p.x, pos->p.y, pos->p.z);
    Vec_002BF008 v;
    v.x = (pos->p.x + w) * D_00392610 - D_00392610 * 29.0f;
    v.z = (pos->p.z + d) * D_00392618 - D_00392618 * 29.0f;
    v.y = pos->p.y * D_00392614;
    for (; i < p->m30; i++) {
        Vec_002BF008 off;
        func_002BB010(&off, p, i);
        Inst_002BF008* n = func_002B6CF8(p->GetModel(i));
        Vec_002BF008 t;
        t.x = v.x + off.x;
        t.z = v.z + off.z;
        t.y = v.y + off.y;
        func_002B6EE8(n, &t, 1);
        func_002B6F30(n, (n->m30 + p->mC) & 3, 1);
        func_002B7940(m0, n);
        func_002B8608(m0, n);
    }
    func_002C1600(this, p, 1);
    func_002C2618(this, p);
    int r = func_002C3270(this, p->m34);
    if (r) func_002BA418(m0, &v, p->mC, pos, r, 0, 0);
    if (!p->IsLocked()) {
        if (!p->IsHidden()) m6A64 &= ~5;
        func_002BEF88(this, p->m34);
    }
}
