struct Obj_00246600 {
    int m_pad[14];
    int m_mask;
    bool Test(int bit);
};

bool Obj_00246600::Test(int bit)
{
    int mask = 1 << bit;
    return (m_mask & mask) != 0;
}
