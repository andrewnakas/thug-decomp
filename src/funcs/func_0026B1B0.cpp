typedef int qword __attribute__((mode(TI)));
union Vec_0026B1B0 {
    qword q;
    float c[4];
    Vec_0026B1B0& operator=(const Vec_0026B1B0& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_0026B1B0 {
    Vec_0026B1B0 r[4];
};

extern "C" void func_00323298(Vec_0026B1B0* out, const Mat_0026B1B0* m, const Vec_0026B1B0* v);

static inline Vec_0026B1B0 operator*(const Mat_0026B1B0& m, const Vec_0026B1B0& v)
{
    Vec_0026B1B0 r;
    func_00323298(&r, &m, &v);
    return r;
}

struct Thing_0026B1B0 {
    char pad[0x30];
    Vec_0026B1B0 m30;
};

struct Xform_0026B1B0 {
    int m0;
    int m4;
    int m8;
    int mC;
    Mat_0026B1B0 m10;
    char pad[0x64 - 0x50];
    int m64;
    Vec_0026B1B0 Apply(Thing_0026B1B0* t);
};

Vec_0026B1B0 Xform_0026B1B0::Apply(Thing_0026B1B0* t)
{
    if (!m64)
        return t->m30;
    Vec_0026B1B0 v = m10 * t->m30;
    return v;
}
