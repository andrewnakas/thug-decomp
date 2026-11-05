extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_00120120 {
    char pad[0x50];
    void* m_50;
    void Free();
};

void Obj_00120120::Free()
{
    if (m_50) {
        func_0010A8D8(D_00388A70, m_50);
        m_50 = 0;
    }
}
