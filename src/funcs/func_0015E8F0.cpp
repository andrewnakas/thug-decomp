extern "C" long func_00168738(void* a, void* b);

struct Obj_0015E8F0 {
    char pad[0x10A0];
    long m_10A0;
    void Set(void* a, void* b);
};

void Obj_0015E8F0::Set(void* a, void* b)
{
    m_10A0 = func_00168738(a, b);
}
