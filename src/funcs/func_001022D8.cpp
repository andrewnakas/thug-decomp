typedef int qword __attribute__((mode(TI)));

struct Vec_001022D8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001022D8() {}
    Vec_001022D8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Box_001022D8 {
    Vec_001022D8 m_min;
    Vec_001022D8 m_max;
    Box_001022D8();
};

Box_001022D8::Box_001022D8()
{
    m_min = Vec_001022D8(10000000.0f, 10000000.0f, 10000000.0f, 1.0f);
    m_max = Vec_001022D8(-10000000.0f, -10000000.0f, -10000000.0f, 1.0f);
}
