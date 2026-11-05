struct Obj0015EC00 {
    char pad[0x203];
    unsigned char m_val;
    void Set(int, unsigned char v);
};

void Obj0015EC00::Set(int, unsigned char v)
{
    m_val = v >> 1;
}
