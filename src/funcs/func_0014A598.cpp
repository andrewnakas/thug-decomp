extern "C" void func_00173030(void* o);

struct Obj_0014A598 {
    int m0[2];
    void* m_8;
    void Free();
};

void Obj_0014A598::Free()
{
    func_00173030(m_8);
    m_8 = 0;
}
