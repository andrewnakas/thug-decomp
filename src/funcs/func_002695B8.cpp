typedef int qword __attribute__((mode(TI)));
struct Vec_002695B8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_002695B8 {
    Vec_002695B8 r[4];
    Mat_002695B8& operator=(const Mat_002695B8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Xform_002695B8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Mat_002695B8 m10;
    char pad[0x64 - 0x50];
    int m_set;
    void Set(const Mat_002695B8& m);
};

void Xform_002695B8::Set(const Mat_002695B8& m)
{
    m_set = 1;
    m10 = m;
}
