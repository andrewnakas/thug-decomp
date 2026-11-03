class Iter_001FDBA8 {
public:
    void* m_node;
    int m_index;
    Iter_001FDBA8() : m_index(0) {}
    virtual ~Iter_001FDBA8() {}
    virtual void Run();
};

struct Conn_001FDBA8 {
    char pad[0x68];
    unsigned int m_flags;
};

struct Mgr_001FDBA8 {
    char pad[0x4298];
    void* m_lock;
};

static inline unsigned int TestFlag_001FDBA8(Conn_001FDBA8* c, const unsigned int& mask)
{
    return c->m_flags & mask;
}

static inline unsigned int HasFlag_001FDBA8(Conn_001FDBA8* c, int flag)
{
    return TestFlag_001FDBA8(c, flag);
}

extern "C" void func_0031BCE0(void* lock);
extern "C" int func_0031BCC0(void* lock);
extern "C" Conn_001FDBA8* func_00200EC0(Mgr_001FDBA8* mgr, Iter_001FDBA8* it);
extern "C" Conn_001FDBA8* func_00200EF8(Mgr_001FDBA8* mgr, Iter_001FDBA8* it);
extern "C" bool func_001FF410(Mgr_001FDBA8* mgr, Conn_001FDBA8* c);
extern "C" bool func_001FF258(Mgr_001FDBA8* mgr, Conn_001FDBA8* c);
extern "C" void func_00202710(Conn_001FDBA8* c);
extern "C" bool func_00202738(Conn_001FDBA8* c);
extern "C" void func_00200F28(Mgr_001FDBA8* mgr, Conn_001FDBA8* c);

int func_001FDBA8(Mgr_001FDBA8* mgr)
{
    Iter_001FDBA8 it;
    func_0031BCE0(mgr->m_lock);
    Conn_001FDBA8* c = func_00200EC0(mgr, &it);
    while (c) {
        Conn_001FDBA8* next = func_00200EF8(mgr, &it);
        if (HasFlag_001FDBA8(c, 8)) {
            if (!func_001FF410(mgr, c))
                func_00202710(c);
        }
        if (!func_00202738(c) && !func_001FF258(mgr, c) && !func_001FF410(mgr, c))
            func_00200F28(mgr, c);
        c = next;
    }
    return func_0031BCC0(mgr->m_lock);
}
