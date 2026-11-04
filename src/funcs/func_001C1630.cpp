typedef int qword __attribute__((mode(TI)));

struct Vec_001C1630 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C1630() {}
    Vec_001C1630(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001C1630& operator=(const Vec_001C1630& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_001C1630 {
    float m[16];
};

struct Res_001C1630 {
    void* h;
    char pad4[0x60 - 4];
    Vec_001C1630 m60;
    Mat_001C1630 m70;
    int mB0;
    void Offset(Vec_001C1630& v) { v.x += m60.x; v.y += m60.y; v.z += m60.z; v.w += m60.w; }
};

extern void* D_00388A70;
extern "C" unsigned int func_0010FC30();
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" int func_0020A760(Res_001C1630* r, Vec_001C1630* pos);
extern "C" void func_003233B8(Vec_001C1630* dst, Vec_001C1630* src);

static inline void Free_001C1630(Res_001C1630* r)
{
    if (r->h) {
        func_00183CB8(r->h, r);
        r->h = 0;
    }
    func_0010A8D8(D_00388A70, r);
}

struct Holder_001C1630 {
    char pad[0x1C];
    Res_001C1630* m1C;
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
        Res_001C1630* r = m1C;
        if (r) {
            Free_001C1630(r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
    bool Update(Vec_001C1630* pos)
    {
        if (!Valid()) return false;
        if (func_0020A760(m1C, pos)) return true;
        Release();
        return false;
    }
};

struct Obj_001C1630 {
    char pad0[0x30];
    Vec_001C1630 m30;
    char pad40[0x20];
    Vec_001C1630 m60;
    char pad70[0xA3C - 0x70];
    Holder_001C1630* mA3C;
    Vec_001C1630 Rotated(const Mat_001C1630& M)
    {
        Vec_001C1630 t;
        t.x = m60.x * M.m[0] + m60.y * M.m[4] + m60.z * M.m[8];
        t.y = m60.x * M.m[1] + m60.y * M.m[5] + m60.z * M.m[9];
        t.z = m60.x * M.m[2] + m60.y * M.m[6] + m60.z * M.m[10];
        t.w = m60.w;
        return t;
    }
    void Follow();
};

void Obj_001C1630::Follow()
{
    Holder_001C1630* h = mA3C;
    if (h->Update(&m30)) {
        mA3C->m1C->Offset(m30);
        if (mA3C->m1C->mB0) {
            m60 = Rotated(mA3C->m1C->m70);
            if (m60.y != 0.0f) {
                m60.y = 0.0f;
                func_003233B8(&m60, &m60);
            }
        }
    }
}
