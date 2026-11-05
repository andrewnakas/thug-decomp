struct Tab_00135F20 {
    char pad[0x3C];
    float m_a[8];
};

extern Tab_00135F20 D_003BEB00;

float Get_00135F20(int i)
{
    return D_003BEB00.m_a[i];
}
