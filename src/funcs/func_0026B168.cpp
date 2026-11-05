typedef int qword __attribute__((mode(TI)));
union Vec_0026B168 {
    qword q;
    float c[4];
    Vec_0026B168& operator=(const Vec_0026B168& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_0026B168 {
    Vec_0026B168 r[4];
};

extern "C" void func_00323298(Vec_0026B168* out, const Mat_0026B168* m, const Vec_0026B168* v);

static inline Vec_0026B168 operator*(const Mat_0026B168& m, const Vec_0026B168& v)
{
    Vec_0026B168 r;
    func_00323298(&r, &m, &v);
    return r;
}

struct Xform_0026B168 {
    int m0;
    int m4;
    int m8;
    int mC;
    Mat_0026B168 m10;
    char pad[0x64 - 0x50];
    int m64;
    Vec_0026B168 Apply(Vec_0026B168* v);
};

Vec_0026B168 Xform_0026B168::Apply(Vec_0026B168* v)
{
    if (!m64)
        return *v;
    return m10 * *v;
}
