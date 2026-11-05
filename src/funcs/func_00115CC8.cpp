struct Fmt_00115CC8 {
    int m0;
    unsigned int m_flags;
    bool Test();
};

bool Fmt_00115CC8::Test()
{
    return (m_flags & 0x9000000) != 0;
}
