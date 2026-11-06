typedef int qword __attribute__((mode(TI)));

struct Vec_0019E748 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019E748& operator*=(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        w *= k;
        return *this;
    }
};

struct Obj_0019E748 {
    char pad0[0x48];
    int m48;
    char pad4C[0x58 - 0x4C];
    float m58;
    char pad5C[0x7C - 0x5C];
    short m7C;
    char pad7E[0xB0 - 0x7E];
    Vec_0019E748 mB0;
    void Fn(const Vec_0019E748* v);
};

void Obj_0019E748::Fn(const Vec_0019E748* v)
{
    Vec_0019E748* p = &mB0;
    *p = *v;
    if (m58 != 1.0f)
        *p *= m58;
    m48 = 0;
    m7C = 2;
}
