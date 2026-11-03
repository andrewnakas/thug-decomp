struct Vec_00289928 {
    float x, y, z, w;
};

struct Mat_00289928 {
    float m[16];
};

struct Res_00289928 {
    void* h;
    char pad4[0x60 - 4];
    Vec_00289928 m60;
    Mat_00289928 m70;
    int mB0;
    void Offset(Vec_00289928& v) { v.x += m60.x; v.y += m60.y; v.z += m60.z; v.w += m60.w; }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" int func_0020A760(Res_00289928* r, Vec_00289928* pos);
extern "C" void func_00323318(Mat_00289928* a, Mat_00289928* b, Mat_00289928* out);
extern "C" float func_001E5318(unsigned int name, int v);

static inline void Free_00289928(Res_00289928* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}

struct Holder_00289928 {
    char pad[0x1C];
    Res_00289928* m1C;
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
        Res_00289928* r = m1C;
        if (r) {
            Free_00289928(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_00289928* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Body_00289928 {
    char pad[0x50];
    Vec_00289928 m50;
    char pad60[0x10];
    Mat_00289928 m70;
};

struct Obj_00289928;
extern "C" void func_0027C720(Obj_00289928* o, int v);

struct Obj_00289928 {
    char pad0[0xC];
    Body_00289928* mC;
    char pad10[0x10];
    Mat_00289928 m20;
    char pad60[0x98 - 0x60];
    unsigned int m98;
    char pad9C[0x29C - 0x9C];
    void* m29C;
    char pad2A0[0x2B4 - 0x2A0];
    int m2B4;
    char pad2B8[0x5B4 - 0x2B8];
    Holder_00289928* m5B4;
    void Tick();
};

void Obj_00289928::Tick()
{
    unsigned int start = m98;
    float t = (float)(func_0010FC30() - start);
    if (func_001E5318(0xA06E446B, 0) < t) {
        func_0027C720(this, 1);
        return;
    }
    m29C = 0;
    m2B4 = 0;
    Holder_00289928* h = m5B4;
    if (h->Update(&mC->m50)) {
        m5B4->m1C->Offset(mC->m50);
        if (m5B4->m1C->mB0) {
            func_00323318(&mC->m70, &m5B4->m1C->m70, &mC->m70);
            func_00323318(&m20, &m5B4->m1C->m70, &m20);
        }
    }
}
