struct Vec_001D49D0 {
    float x, y, z, w;
};

struct Box_001D49D0 {
    Vec_001D49D0 m_min;
    Vec_001D49D0 m_max;
};

extern "C" void func_001D4880(void* self);

struct Obj_001D49D0 {
    char m_pad[0x20];
    Vec_001D49D0 m_min;
    Vec_001D49D0 m_max;
    int m_dirty;
    int m_valid;
    bool Overlaps(const Box_001D49D0* b)
    {
        if (b->m_min.x > m_max.x ||
            m_min.x > b->m_max.x ||
            b->m_min.z > m_max.z ||
            m_min.z > b->m_max.z ||
            b->m_min.y > m_max.y ||
            m_min.y > b->m_max.y)
            return false;
        return true;
    }
    bool Touches(const Box_001D49D0* box);
};

bool Obj_001D49D0::Touches(const Box_001D49D0* box)
{
    if (m_dirty) {
        func_001D4880(this);
        m_dirty = 0;
    }
    bool r = false;
    if (!m_valid || Overlaps(box))
        r = true;
    return r;
}
