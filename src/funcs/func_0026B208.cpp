typedef int qword __attribute__((mode(TI)));
struct Vec_0026B208 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0026B208 {
    Vec_0026B208 r[4];
    Mat_0026B208() {}
    const Vec_0026B208& operator[](int i) const { return r[i]; }
    Mat_0026B208(const Mat_0026B208& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0026B208 operator*(const Mat_0026B208& b) const;
    Mat_0026B208& operator=(const Mat_0026B208& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Mat_0026B208& Set(struct Xform_0026B208* x, struct Thing_0026B208* t);
};

extern "C" void func_0026B350(void* q, Mat_0026B208* out);
extern "C" void func_00323318(Mat_0026B208* out, const Mat_0026B208* a, Mat_0026B208* b);

inline Mat_0026B208 Mat_0026B208::operator*(const Mat_0026B208& b) const
{
    Mat_0026B208 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Xform_0026B208 {
    int m0;
    int m4;
    int m8;
    int mC;
    Mat_0026B208 m10;
    char pad[0x64 - 0x50];
    int m64;
};

struct Thing_0026B208 {
    char pad[0x40];
    char m40[0x10];
};

static inline Mat_0026B208 Compose_0026B208(Xform_0026B208* x, Thing_0026B208* t)
{
    Mat_0026B208 q;
    func_0026B350(t->m40, &q);
    return x->m10 * q;
}

Mat_0026B208& Mat_0026B208::Set(Xform_0026B208* x, Thing_0026B208* t)
{
    if (!x->m64) {
        func_0026B350(t->m40, this);
    } else {
        *this = Compose_0026B208(x, t);
    }
    return *this;
}
