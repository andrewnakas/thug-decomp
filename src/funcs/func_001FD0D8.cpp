extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(int a, int b, void* msg);

struct Msg_001FD0D8 {
    unsigned char m_type;
    char pad1[0x1F];
};

struct Inner_001FD0D8 {
    char pad0[0x48];
    int m_48;
    char pad4C[0x68 - 0x4C];
    unsigned int m_flags;
};

static inline unsigned int TestFlag_001FD0D8(Inner_001FD0D8* c, const unsigned int& mask)
{
    return c->m_flags & mask;
}

static inline unsigned int HasFlag_001FD0D8(Inner_001FD0D8* c, int flag)
{
    return TestFlag_001FD0D8(c, flag);
}

static inline void OrFlag_001FD0D8(Inner_001FD0D8* c, const unsigned int& mask)
{
    c->m_flags |= mask;
}

static inline void SetFlag_001FD0D8(Inner_001FD0D8* c, int flag)
{
    OrFlag_001FD0D8(c, flag);
}

struct Obj_001FD0D8 {
    char pad0[0x10];
    int m_10;
    Inner_001FD0D8* m_14;
    int Run();
};

int Obj_001FD0D8::Run()
{
    Msg_001FD0D8 msg;
    func_001FA800(&msg);
    if (HasFlag_001FD0D8(m_14, 8))
        return 3;
    msg.m_type = 12;
    func_001FF970(m_10, m_14->m_48, &msg);
    SetFlag_001FD0D8(m_14, 8);
    return 1;
}
