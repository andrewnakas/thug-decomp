extern "C" long func_00168738(void* a, void* b);

struct Obj_0015E8C0 {
    char pad[0x1098];
    long m_1098;
    void Set(void* a, void* b);
};

void Obj_0015E8C0::Set(void* a, void* b)
{
    m_1098 = func_00168738(a, b);
}
