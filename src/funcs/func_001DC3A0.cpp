struct Obj_001DC3A0 {
    char pad0[8];
    float m_max;
    float m_min;
};

extern "C" float func_001DC3A0(Obj_001DC3A0* o, int clamp, float t)
{
    if (o->m_min != 0.0f || o->m_max != 100.0f)
        t = o->m_min + (o->m_max - o->m_min) * t * 0.01f;
    if (clamp && o->m_max < t)
        t = o->m_max;
    return t;
}
