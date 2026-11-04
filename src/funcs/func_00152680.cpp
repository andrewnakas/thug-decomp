struct Obj00152680 {
    char pad[0x21b];
    unsigned char m_val;
    void Set(int, unsigned char v);
};

void Obj00152680::Set(int, unsigned char v)
{
    m_val = v >> 1;
}
