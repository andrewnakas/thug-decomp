typedef int qword __attribute__((mode(TI)));

struct Vec_00103E60 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00103E60() {}
    Vec_00103E60(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Rot_00103E60 {
    char pad0[0x80];
    Vec_00103E60 m_axis;
    float m_angle;
    void Invert();
};

void Rot_00103E60::Invert()
{
    m_axis = Vec_00103E60(-m_axis.x, -m_axis.y, -m_axis.z, -m_axis.w);
    m_angle = 6.2831855f - m_angle;
}
