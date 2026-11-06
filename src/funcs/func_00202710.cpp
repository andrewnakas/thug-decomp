struct Conn_00202710 {
    char pad[0x68];
    int m_flags;
};

static inline void SetFlag_00202710(Conn_00202710* c, const unsigned int& mask)
{
    c->m_flags |= mask;
}

static inline void AddFlag_00202710(Conn_00202710* c, int flag)
{
    SetFlag_00202710(c, flag);
}

extern "C" void func_00202710(Conn_00202710* c)
{
    c->m_flags &= ~1;
    AddFlag_00202710(c, 4);
}
