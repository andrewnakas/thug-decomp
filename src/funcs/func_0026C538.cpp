struct Vec_0026C538 {
    float x, y, z, w;
    Vec_0026C538() {}
    Vec_0026C538(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Vol_0026C538 {
    char pad0[0x10];
    Vec_0026C538 m_center;
    char pad20[0x34 - 0x20];
    int m_type;
    int pad38;
    float m_radiusSq;
    char pad40[0x10];
    Vec_0026C538 m_min;
    Vec_0026C538 m_max;
    bool InBox(const Vec_0026C538* p) const
    {
        return m_min.x <= p->x && m_min.y <= p->y && m_min.z <= p->z && p->x <= m_max.x && p->y <= m_max.y
            && p->z <= m_max.z;
    }
    Vec_0026C538 OffsetFrom(const Vec_0026C538& a) const
    {
        return Vec_0026C538(a.x - m_center.x, a.y - m_center.y, a.z - m_center.z, a.w - m_center.w);
    }
};

bool func_0026C538(Vol_0026C538* self, Vec_0026C538* p)
{
    bool result = false;
    Vec_0026C538 d = self->OffsetFrom(*p);
    float dist = d.x * d.x + d.y * d.y + d.z * d.z;
    switch (self->m_type) {
    case 2:
        result = dist <= self->m_radiusSq;
        break;
    case 0:
        result = self->InBox(p);
        break;
    }
    return result;
}
