typedef int qword __attribute__((mode(TI)));

struct F_00142440 {
    float v;
    F_00142440& operator=(const F_00142440& o)
    {
        v = o.v;
        return *this;
    }
};

struct Vec_00142440 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00142440 {
    Vec_00142440 r[4];
    const Vec_00142440& operator[](int i) const { return r[i]; }
    Mat_00142440& operator=(const Mat_00142440& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Col_00142440 {
    unsigned char r, g, b, a;
};

template <class T> static inline void Copy3(T* d, const T* s)
{
    T* p = d;
    int n = 2;
    const T* q = s;
    while (n != -1) {
        *p = *q;
        n--;
        p++;
        q++;
    }
}

class C_00142440 {
public:
    int m0, m4, m8;
    F_00142440 m0C[3];
    F_00142440 m18[3];
    int m24;
    float m28, m2C, m30;
    Mat_00142440 m40;
    Vec_00142440 m80[3];
    Vec_00142440 mB0[3];
    int mE0;
    Vec_00142440 mF0[3];
    int m120;
    float m124;
    Col_00142440 m128[3];
    int m134, m138, m13C, m140, m144, m148, m14C, m150, m154;
    C_00142440& operator=(const C_00142440& o);
};

C_00142440& C_00142440::operator=(const C_00142440& o)
{
    m0 = o.m0;
    m4 = o.m4;
    m8 = o.m8;
    Copy3(m0C, o.m0C);
    Copy3(m18, o.m18);
    m24 = o.m24;
    m28 = o.m28;
    m2C = o.m2C;
    m30 = o.m30;
    m40 = o.m40;
    Copy3(m80, o.m80);
    Copy3(mB0, o.mB0);
    mE0 = o.mE0;
    Copy3(mF0, o.mF0);
    m120 = o.m120;
    m124 = o.m124;
    Copy3(m128, o.m128);
    m134 = o.m134;
    m138 = o.m138;
    m13C = o.m13C;
    m140 = o.m140;
    m144 = o.m144;
    m148 = o.m148;
    m14C = o.m14C;
    m150 = o.m150;
    m154 = o.m154;
    return *this;
}
