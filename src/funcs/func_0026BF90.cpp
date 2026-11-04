struct Vec_0026BF90 {
    float x, y, z, w;
};

struct Box_0026BF90 {
    Vec_0026BF90 min;
    Vec_0026BF90 max;
};

struct Region_0026BF90 {
    char m_pad[0x10];
    Vec_0026BF90 m_center;
    char m_pad20[0x48 - 0x20];
    int m_type;
    char m_pad4C[0x50 - 0x4C];
    float m_radiusSq;
    char m_pad54[0x60 - 0x54];
    Box_0026BF90 m_box;
    bool InBox(const Vec_0026BF90& p) const
    {
        return m_box.min.x <= p.x && m_box.min.y <= p.y && m_box.min.z <= p.z && p.x <= m_box.max.x &&
               p.y <= m_box.max.y && p.z <= m_box.max.z;
    }
    bool Inside(const Vec_0026BF90* p);
};

bool Region_0026BF90::Inside(const Vec_0026BF90* p)
{
    Vec_0026BF90 d;
    d.x = p->x - m_center.x;
    d.y = p->y - m_center.y;
    d.z = p->z - m_center.z;
    d.w = p->w - m_center.w;
    float dist = d.x * d.x + d.y * d.y + d.z * d.z;
    bool r = false;
    switch (m_type) {
    case 0:
        r = dist <= m_radiusSq;
        break;
    case 1:
        r = InBox(*p);
        break;
    }
    return r;
}
