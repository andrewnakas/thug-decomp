struct Obj00152630 {
    char pad[0x213];
    unsigned char m_val;
    void Set(int i, unsigned char v);
};

void Obj00152630::Set(int i, unsigned char v)
{
    m_val = v >> 1;
}
