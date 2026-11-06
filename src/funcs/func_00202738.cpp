struct Conn_00202738 {
    char pad[0x68];
    int m_flags;
};

static inline unsigned int TestFlag_00202738(Conn_00202738* c, const unsigned int& mask)
{
    return c->m_flags & mask;
}

static inline unsigned int HasFlag_00202738(Conn_00202738* c, int flag)
{
    return TestFlag_00202738(c, flag);
}

extern "C" bool func_00202738(Conn_00202738* c)
{
    return !HasFlag_00202738(c, 4);
}
