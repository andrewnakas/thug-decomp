typedef int qword __attribute__((mode(TI)));

struct Vec_00123AE8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    bool operator==(const Vec_00123AE8& o) const
    {
        return x == o.x && y == o.y && z == o.z && w == o.w;
    }
    bool operator!=(const Vec_00123AE8& o) const { return !(*this == o); }
};

struct C_00123AE8 {
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x90 - 0x10];
    Vec_00123AE8 m90;
    char padA0[0xD0 - 0xA0];
    char mD0[0x10];
    Vec_00123AE8 mE0;
    void SetColor(Vec_00123AE8* v, int f);
};

extern "C" void func_00125798(C_00123AE8* self, void* p);

void C_00123AE8::SetColor(Vec_00123AE8* v, int f)
{
    if (mE0 != *v) {
        mE0 = *v;
        m_flags |= 0x400;
        func_00125798(this, mD0);
    }
    if (f) {
        if (m90 != *v) {
            m90 = *v;
            m_flags |= 0x400;
        }
    }
    m_flags |= 0x80000;
}
