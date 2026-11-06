struct Comp_001E5040 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m_type;
    char m_pad3[0xC - 3];
    int m_val;
};

extern "C" Comp_001E5040* func_001E4FC8(int key);

extern "C" Comp_001E5040* func_001E5040(int key)
{
    Comp_001E5040* c = func_001E4FC8(key);
    while (c && c->m_type == 13) {
        Comp_001E5040* n = func_001E4FC8(c->m_val);
        if (!n)
            return c;
        if (n->m_type != 13)
            return n;
        c = n;
    }
    return c;
}
