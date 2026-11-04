typedef int qword_00258F18 __attribute__((mode(TI)));

struct Vec_00258F18 {
    union {
        qword_00258F18 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_00258F18() {}
    Vec_00258F18(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
    Vec_00258F18& operator*=(float s)
    {
        f.x *= s;
        f.y *= s;
        f.z *= s;
        f.w *= s;
        return *this;
    }
    Vec_00258F18& operator+=(const Vec_00258F18& o)
    {
        f.x += o.f.x;
        f.y += o.f.y;
        f.z += o.f.z;
        f.w += o.f.w;
        return *this;
    }
};

struct Obj_00258F18 {
    char pad0[0x10];
    Vec_00258F18 m_pos;
    char pad20[0x60];
    Vec_00258F18 m_start;
    Vec_00258F18 m_end;
    char padA0[0x1C];
    float m_duration;
    float m_time;

    void UpdatePos();
};

void Obj_00258F18::UpdatePos()
{
    Vec_00258F18 d;
    d = Vec_00258F18(m_end.f.x - m_start.f.x, m_end.f.y - m_start.f.y, m_end.f.z - m_start.f.z, m_end.f.w - m_start.f.w);
    m_pos = m_start;
    d *= m_time / m_duration;
    m_pos += d;
}
