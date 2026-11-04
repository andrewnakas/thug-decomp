struct Obj00152658 {
    char pad[0x217];
    unsigned char m_val;
    void Set(int, unsigned char v);
};

void Obj00152658::Set(int, unsigned char v)
{
    m_val = v >> 1;
}
