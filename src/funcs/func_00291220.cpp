extern "C" float func_00203DB0(void*, void*, void*);
extern "C" void* func_001E5548(unsigned int, int);

static inline float Ev(void* n, void* p, unsigned int h)
{
    return func_00203DB0(n, p, func_001E5548(h, 0));
}

struct Obj_00291220 {
    char pad0[0xC];
    void* m_node;
    char pad1[0x1C - 0x10];
    unsigned int m1C;
    char pad2[0x24 - 0x20];
    void* m24;
    float Eval(void* p);
};

float Obj_00291220::Eval(void* p)
{
    if (m24) return func_00203DB0(m_node, p, m24);
    switch (m1C) {
    case 0x0AC90769:
    case 0xEF24413B:
        return Ev(m_node, p, 0xB8CC8633);
    case 0x255ED86F:
    case 0x8D10119D:
        return Ev(m_node, p, 0x6B7FDADD);
    case 0xA549B57B:
        return Ev(m_node, p, 0xBE615D0A);
    case 0x3506CE64:
        return Ev(m_node, p, 0xFC87CC01);
    }
    return 0.0f;
}
