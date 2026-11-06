typedef int qword __attribute__((mode(TI)));

struct Vec_0011D528 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0011D528() {}
    Vec_0011D528(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

class Elem_0011D528 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14[3];
    Vec_0011D528 m_scale;
    Elem_0011D528();
};

Elem_0011D528::Elem_0011D528()
{
    m10 = -1;
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
    m_scale = Vec_0011D528(1.0f, 1.0f, 1.0f, 1.0f);
}
