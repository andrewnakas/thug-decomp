struct Tab_00135EF8 {
    char pad[0x3C];
    float m_a[8];
};

extern Tab_00135EF8 D_003BEB00;

void Set_00135EF8(int i, float f)
{
    D_003BEB00.m_a[i] = f;
}
