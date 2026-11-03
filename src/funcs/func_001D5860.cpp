struct Box_001D5860 {
    float m_min[4];
    float m_max[4];
};

struct Holder_001D5860 {
    char m_pad[0x10];
    float m_min[4];
    float m_max[4];
};

struct Obj_001D5860 {
    int m0;
    int m4;
    Holder_001D5860* m8;
    bool Overlaps(const Box_001D5860* o);
};

bool Obj_001D5860::Overlaps(const Box_001D5860* o)
{
    Holder_001D5860* b = m8;
    if (o->m_min[0] > b->m_max[0] || b->m_min[0] > o->m_max[0] ||
        o->m_min[2] > b->m_max[2] || b->m_min[2] > o->m_max[2] ||
        o->m_min[1] > b->m_max[1] || b->m_min[1] > o->m_max[1]) {
        return false;
    }
    return true;
}
