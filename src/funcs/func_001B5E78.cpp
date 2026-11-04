struct List_001B5E78 {
    int m_pad[3];
    int m_count;
};

extern "C" List_001B5E78* func_001E55B8(unsigned int id, int flags);
extern "C" unsigned int func_001E9300(List_001B5E78* l, int i);
extern "C" void func_001F0E98(void* obj, unsigned int name);

struct C_001B5E78 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    void Clear();
};

void C_001B5E78::Clear()
{
    List_001B5E78* l = func_001E55B8(0x2ECD9F57, 1);
    int n = l->m_count;
    void* o = mC;
    for (int i = 0; i < n; i++) {
        func_001F0E98(o, func_001E9300(l, i));
    }
    m20 &= ~4u;
    m20 &= ~0x200u;
    m20 &= ~0x400u;
}
