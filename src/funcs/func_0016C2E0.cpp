typedef int qword __attribute__((mode(TI)));

struct Vec {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec() {}
    Vec& operator=(const Vec& o) { q = o.q; return *this; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Rows_0016C2E0 {
    Vec r[3];
};


class Obj_0016C2E0 {
public:
    int m_flag;
    Rows_0016C2E0 m_a;
    Rows_0016C2E0 m_b;
    Vec m_c;
    Rows_0016C2E0 m_d;
    Vec m_e;
    Obj_0016C2E0();
};

extern Obj_0016C2E0 D_003DD9E0;

Obj_0016C2E0::Obj_0016C2E0()
{
    if (this != &D_003DD9E0) {
        m_flag = 0;
        m_a = D_003DD9E0.m_a;
        m_b = D_003DD9E0.m_b;
        m_d = D_003DD9E0.m_b;
        m_c = D_003DD9E0.m_c;
        m_e = D_003DD9E0.m_c;
    } else {
        m_a.r[0].Set(0.0f, -1.0f, 0.0f, 1.0f);
        m_a.r[1].Set(0.0f, -1.0f, 0.0f, 1.0f);
        m_a.r[2].Set(0.0f, -1.0f, 0.0f, 1.0f);
        m_b.r[0].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_b.r[1].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_b.r[2].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_d.r[0].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_d.r[1].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_d.r[2].Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_c.Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_e.Set(0.0f, 0.0f, 0.0f, 1.0f);
    }
}
