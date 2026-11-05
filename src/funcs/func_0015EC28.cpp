struct Obj0015EC28 {
    char pad[0x207];
    unsigned char m_val;
    void Set(int, unsigned char v);
};

void Obj0015EC28::Set(int, unsigned char v)
{
    m_val = v >> 1;
}
