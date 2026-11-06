struct Comp_001E5318 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m_type;
    char pad3[9];
    union {
        int i;
        float f;
    } m_value;
};

extern "C" Comp_001E5318* func_001E5040(unsigned int id);

extern "C" float func_001E5318(unsigned int id)
{
    Comp_001E5318* c = func_001E5040(id);
    if (c) {
        switch (c->m_type) {
        case 2:
            return c->m_value.f;
        case 1:
            return c->m_value.i;
        }
    }
    return 0.0f;
}
