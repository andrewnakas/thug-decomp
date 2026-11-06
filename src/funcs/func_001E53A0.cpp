struct Node_001E53A0 {
    char m0;
    char m1;
    unsigned char m_type;
    char m3;
    int m4;
    int m8;
    union {
        int i;
        float f;
    } mC;
};

extern "C" Node_001E53A0* func_001E5040(unsigned int crc, int a);

extern "C" int func_001E53A0(unsigned int crc, int a)
{
    Node_001E53A0* n = func_001E5040(crc, a);
    if (!n)
        return 0;
    switch (n->m_type) {
    case 2:
        return (int)n->mC.f;
    case 1:
        return n->mC.i;
    }
    return 0;
}
