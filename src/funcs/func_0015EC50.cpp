struct Obj0015EC50 {
    char pad[0x20b];
    unsigned char m_val;
    void Set(int, unsigned char v);
};

void Obj0015EC50::Set(int, unsigned char v)
{
    m_val = v >> 1;
}
