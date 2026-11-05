struct Obj_0014B780 {
    int m0[7];
    unsigned int* m_1C;
    void SetMaster(int on);
};

void Obj_0014B780::SetMaster(int on)
{
    unsigned int* p = m_1C;
    if (on)
        *p |= 1;
    else
        *p &= ~1;
}
