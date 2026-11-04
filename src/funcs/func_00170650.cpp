struct Obj170650 {
    char pad[0x1C];
    int m_flags;
    int m20;
    int Get20() const;
};

int Obj170650::Get20() const
{
    int v = 0;
    if (m_flags & 2)
        v = m20;
    return v;
}
