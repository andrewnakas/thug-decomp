extern "C" long func_00168738(void* a, void* b);

struct Obj_0015E920 {
    char pad[0x10A8];
    long m_10A8;
    void Set(void* a, void* b);
};

void Obj_0015E920::Set(void* a, void* b)
{
    m_10A8 = func_00168738(a, b);
}
