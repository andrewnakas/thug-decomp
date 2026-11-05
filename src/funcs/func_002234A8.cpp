struct Array_002234A8 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" int func_001E9300(Array_002234A8* a, unsigned int i);

extern "C" bool func_002234A8(Array_002234A8* a, int v)
{
    if (!a)
        return false;
    unsigned int n = a->m_size;
    for (unsigned int i = 0; i < n; i++) {
        if (v == func_001E9300(a, i))
            return true;
    }
    return false;
}
