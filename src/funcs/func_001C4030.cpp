typedef int qword __attribute__((mode(TI)));

struct Vec_001C4030 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C4030() {}
    Vec_001C4030(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    Vec_001C4030& operator+=(const Vec_001C4030& o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
};

struct Body_001C4030 {
    char m_pad0[0xB0];
    Vec_001C4030 mB0;
};

struct Ref_001C4030 {
    Body_001C4030* p;
};

struct Heap_001C4030;
extern Heap_001C4030* D_00388A70;
extern "C" void func_0010A8D8(Heap_001C4030* h, void* p);
extern "C" int func_0010FC30();
extern "C" void func_00183CB8(void* p, void* ref);

struct Link_001C4030 {
    char m_pad0[0x1C];
    Ref_001C4030* m1C;
    int m20;
    bool Valid()
    {
        Ref_001C4030* r = m1C;
        if (!r) {
            return false;
        }
        if (r->p) {
            return true;
        }
        func_0010A8D8(D_00388A70, r);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
    void Release()
    {
        Ref_001C4030* r = m1C;
        if (r) {
            if (r->p) {
                func_00183CB8(r->p, r);
                r->p = 0;
            }
            func_0010A8D8(D_00388A70, r);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};

struct Obj_001C4030 {
    char m_pad0[0x30];
    Vec_001C4030 m30;
    char m_pad40[0x58];
    float m98;
    char m_pad9C[0xA3C - 0x9C];
    Link_001C4030* mA3C;
    char m_padA40[0xB80 - 0xA40];
    Vec_001C4030 mB80;
    void Take(Vec_001C4030& a, float* f);
};

void Obj_001C4030::Take(Vec_001C4030& a, float* f)
{
    if (mA3C->Valid()) {
        mB80 = mA3C->m1C->p->mB0;
        if (mB80.x * a.x + mB80.y * a.y + mB80.z * a.z > 0.0f) {
            Vec_001C4030 t(mB80.x * m98, mB80.y * m98, mB80.z * m98, mB80.w * m98);
            m30 += t;
        }
        *f += mB80.y;
        mB80.y = 0.0f;
        a.x += mB80.x;
        a.y += mB80.y;
        a.z += mB80.z;
        a.w += mB80.w;
    } else {
        mB80.Set(0.0f, 0.0f, 0.0f);
    }
    mA3C->Release();
}
