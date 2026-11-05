typedef int qword __attribute__((mode(TI)));
union Vec_0026B6A8 {
    qword q;
    float c[4];
    Vec_0026B6A8& operator=(const Vec_0026B6A8& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_0026B6A8 {
    Vec_0026B6A8 r[4];
};

extern "C" void func_00323298(Vec_0026B6A8* out, const Mat_0026B6A8* m, const Vec_0026B6A8* v);
extern "C" Vec_0026B6A8* func_0026B6A0(void* p);

static inline Vec_0026B6A8 operator*(const Mat_0026B6A8& m, const Vec_0026B6A8& v)
{
    Vec_0026B6A8 r;
    func_00323298(&r, &m, &v);
    return r;
}

struct Xform_0026B6A8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Mat_0026B6A8 m10;
    Vec_0026B6A8 Apply(void* p);
};

Vec_0026B6A8 Xform_0026B6A8::Apply(void* p)
{
    if (!m8)
        return *func_0026B6A0(p);
    Vec_0026B6A8 v = m10 * *func_0026B6A0(p);
    return v;
}
