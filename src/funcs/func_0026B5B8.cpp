typedef int qword __attribute__((mode(TI)));
struct Vec_0026B5B8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0026B5B8 {
    Vec_0026B5B8 r[4];
    Mat_0026B5B8& operator=(const Mat_0026B5B8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Xform_0026B5B8 {
    int m0;
    int m4;
    int m_set;
    int mC;
    Mat_0026B5B8 m10;

    void Set(const Mat_0026B5B8& m);
};

void Xform_0026B5B8::Set(const Mat_0026B5B8& m)
{
    m_set = 1;
    m10 = m;
}
