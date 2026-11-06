struct Map_00183B48 {
    int m_mask;
    int m_index;
};

extern Map_00183B48 D_0034ECF8[];

struct Pad_00183B48 {
    char m0;
    unsigned char m1[0x19];
    char pad1A[0x1C - 0x1A];
    unsigned int m1C;
    void Fn();
};

void Pad_00183B48::Fn()
{
    for (int i = 0; D_0034ECF8[i].m_mask > 0; i++) {
        if (m1C & D_0034ECF8[i].m_mask)
            m1[D_0034ECF8[i].m_index] = 0xFF;
        else
            m1[D_0034ECF8[i].m_index] = 0;
    }
}
