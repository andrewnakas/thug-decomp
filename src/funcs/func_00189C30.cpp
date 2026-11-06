extern "C" void func_00188DF0(void* q, int x, int y, int z, int a, int b, int kind);

struct Obj_00189C30 {
    int m0[8];
    char m_20[4];
    void Push();
};

void Obj_00189C30::Push()
{
    func_00188DF0(m_20, 0, 0, 0, 0, 0, 3);
}
