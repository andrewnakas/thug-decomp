struct State_0028C0F0 { int pad; int state; unsigned int time; };
extern "C" unsigned int func_0010FC30();
static inline void SetState_0028C0F0(State_0028C0F0* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Vec_0028C0F0 {
    float x, y, z, w;
    void Add(const Vec_0028C0F0& o) { x += o.x; y += o.y; z += o.z; w += o.w; }
};

struct Mat_0028C0F0 {
    float m[16];
};

struct Res_0028C0F0 {
    void* h;
    char pad4[0x60 - 4];
    Vec_0028C0F0 m60;
    Mat_0028C0F0 m70;
    int mB0;
    void Offset(Vec_0028C0F0& v) { v.x += m60.x; v.y += m60.y; v.z += m60.z; v.w += m60.w; }
};

extern void* D_00388A70;
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" int func_0020A760(Res_0028C0F0* r, Vec_0028C0F0* pos);
extern "C" void func_00323318(Mat_0028C0F0* a, Mat_0028C0F0* b, Mat_0028C0F0* out);

static inline void Free_0028C0F0(Res_0028C0F0* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}

struct Holder_0028C0F0 {
    char pad[0x1C];
    Res_0028C0F0* m1C;
    unsigned int m20;
    bool Valid()
    {
        if (!m1C) return false;
        if (m1C->h) return true;
        func_0010A8D8(D_00388A70, m1C);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
    void Release()
    {
        Res_0028C0F0* r = m1C;
        if (r) {
            Free_0028C0F0(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_0028C0F0* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Sub_0028C0F0 {
    char pad[0xA8];
    State_0028C0F0 mA8;
    State_0028C0F0 mB4;
    char padC0[0xF0 - 0xC0];
    State_0028C0F0 mF0;
};

struct Body_0028C0F0 {
    char pad[0x50];
    Vec_0028C0F0 m50;
    char pad60[0x10];
    Mat_0028C0F0 m70;
};

struct Skater_0028C0F0 {
    char pad[0x1C];
    unsigned int m1C;
    char pad20[0x130 - 0x20];
    char m130[0x16C - 0x130];
    int m16C;
    int m170;
};

struct Game_0028C0F0 {
    char pad[0x24];
    void* m24;
};

struct Rec_0028C0F0 {
    char pad[0x5C];
    short m5C;
};

struct Flag_0028C0F0 {
    char pad[0x58];
    int m58;
};

extern Game_0028C0F0* D_0038FC78;
extern int D_00390EF8;
extern "C" int func_00263BD8(void*, unsigned int);
extern "C" void func_00263C18(void*, int);
extern "C" int func_001E53A0(unsigned int name, int v);
extern "C" void func_00260A28(void* p);
extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" void func_001B0EF0(void* p, int v);

struct Obj_0028C0F0;
extern "C" void func_0028E170(Obj_0028C0F0* o);
extern "C" int func_00285258(Obj_0028C0F0* o);
extern "C" void func_0028DF70(Obj_0028C0F0* o, int v);

struct Obj_0028C0F0 {
    char pad0[0xC];
    Body_0028C0F0* mC;
    char pad10[0x10];
    Mat_0028C0F0 m20;
    char pad60[0x29C - 0x60];
    Rec_0028C0F0* m29C;
    Flag_0028C0F0* m2A0;
    char pad2A4[4];
    unsigned int m2A8;
    char pad2AC[4];
    int m2B0;
    char pad2B4[0x2E0 - 0x2B4];
    Vec_0028C0F0 m2E0;
    char pad2F0[0x5A0 - 0x2F0];
    void* m5A0;
    char pad5A4[0x5AC - 0x5A4];
    Skater_0028C0F0* m5AC;
    Sub_0028C0F0* m5B0;
    Holder_0028C0F0* m5B4;
    void Tick();
};

void Obj_0028C0F0::Tick()
{
    SetState_0028C0F0(&m5B0->mA8, 0);
    SetState_0028C0F0(&m5B0->mF0, 0);
    SetState_0028C0F0(&m5B0->mB4, 0);
    Holder_0028C0F0* h = m5B4;
    if (h->Update(&mC->m50)) {
        m5B4->m1C->Offset(mC->m50);
        m5B4->m1C->Offset(m2E0);
        if (m5B4->m1C->mB0) {
            func_00323318(&mC->m70, &m5B4->m1C->m70, &mC->m70);
            func_00323318(&m20, &m5B4->m1C->m70, &m20);
        }
    }
    if (m5AC->m1C == 0xA549B57B) {
        if (func_00263BD8(D_0038FC78->m24, 0xCD09E062)) {
            void* p = D_0038FC78->m24;
            func_00263C18(p, func_001E53A0(0xCD09E062, 0));
            m5AC->m16C = 0;
            m5AC->m170 = 0;
            D_00390EF8 = 1;
        }
        func_00260A28(m5AC->m130);
    }
    func_0028E170(this);
    if (func_00285258(this)) func_0028DF70(this, 9);
    Rec_0028C0F0* r = m29C;
    if (r && m2A0->m58) {
        func_001E8398(func_001E9378(func_001E55B8(0xC472ECC5, 0), r->m5C), 0xA1DC81F9, &m2B0, 1);
        func_001B0EF0(m5A0, m2B0);
    }
    m2A8 = func_0010FC30();
}
