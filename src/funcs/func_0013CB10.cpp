struct Src_0013CB10 {
    int m0;
    int m4;
    int m_count;
};

struct Range_0013CB10 {
    int m0;
    float m_near;
    int m8;
    float m_far;
};

extern "C" Range_0013CB10* func_0013CB10(Range_0013CB10* r, Src_0013CB10* s)
{
    if (s->m_count > 0) {
        r->m0 = 0;
        r->m_near = 36.0f;
        r->m8 = 0;
        r->m_far = 48.0f;
    } else {
        r->m0 = 0;
        r->m_near = 36.0f;
        r->m8 = 0;
        r->m_far = 1200.0f;
    }
    return r;
}
