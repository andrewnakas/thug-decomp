struct Obj170528 {
    char pad[0x1C];
    int m_flags;
    int Bit2() const;
};

int Obj170528::Bit2() const
{
    return (m_flags >> 2) & 1;
}
