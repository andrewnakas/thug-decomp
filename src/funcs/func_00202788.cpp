struct Conn_00202788 {
    char pad[0x68];
    int m_flags;
    char pad6C[0x20B4 - 0x6C];
    int m20B4;
};

static inline unsigned int TestFlag_00202788(Conn_00202788* c, const unsigned int& mask)
{
    return c->m_flags & mask;
}

static inline unsigned int HasFlag_00202788(Conn_00202788* c, int flag)
{
    return TestFlag_00202788(c, flag);
}

static inline int Max_00202788(int a, int b)
{
    int r = b;
    if (a >= b) r = a;
    return r;
}

extern "C" int func_00202768(Conn_00202788* c);

extern "C" int func_00202788(Conn_00202788* c)
{
    if (HasFlag_00202788(c, 2))
        return 1000;
    int n = func_00202768(c) ? 0 : c->m20B4;
    return Max_00202788(n * 2, 500);
}
