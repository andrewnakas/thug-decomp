struct Obj_0014B7B0 {
    int m0[7];
    unsigned int* m_1C;
    void SetChannel(int i, int on);
};

void Obj_0014B7B0::SetChannel(int i, int on)
{
    unsigned int* p = m_1C;
    if (on)
        *p |= 2 << i;
    else
        *p &= ~(2 << i);
}
