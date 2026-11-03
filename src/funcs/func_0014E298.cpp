extern "C" void func_00171D20(void* p, int x, int k);

struct Obj0014E298 {
    char pad[0x20];
    void* m_p;
    void Run(int x);
};

void Obj0014E298::Run(int x)
{
    func_00171D20(m_p, x, 1);
}
