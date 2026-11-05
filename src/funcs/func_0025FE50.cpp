typedef int qword __attribute__((mode(TI)));

struct Vec_0025FE50 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0025FE50 {
    Vec_0025FE50 row[4];
    void Set(const Vec_0025FE50& a, const Vec_0025FE50& b, const Vec_0025FE50& c, const Vec_0025FE50& d)
    {
        row[0].q = a.q;
        row[1].q = b.q;
        row[2].q = c.q;
        row[3].q = d.q;
    }
};

struct Id_0025FE50 {
    int v;
    Id_0025FE50() {}
    Id_0025FE50(const Id_0025FE50& o) { v = o.v; }
};

struct Hdr_0025FE50 {
    int m0;
    int m4;
    Id_0025FE50 m8;
    int mC[15];
};

struct Obj_0025FE50 {
    Hdr_0025FE50 m0;
    char pad48[8];
    Vec_0025FE50 m50;
    Vec_0025FE50 m60;
    Mat_0025FE50 m70;
    float mB0;
    float mB4;
    float mB8;
    float mBC;
    Obj_0025FE50& operator=(const Obj_0025FE50& o);
};

Obj_0025FE50& Obj_0025FE50::operator=(const Obj_0025FE50& o)
{
    Id_0025FE50 keep = m0.m8;
    m0 = o.m0;
    m0.m8 = keep;
    m50.q = o.m50.q;
    m60.q = o.m60.q;
    m70.Set(o.m70.row[0], o.m70.row[1], o.m70.row[2], o.m70.row[3]);
    mB0 = o.mB0;
    mB4 = o.mB4;
    mB8 = o.mB8;
    mBC = o.mBC;
    return *this;
}
