extern "C" void func_00171690(void* p, int x, int k);

struct Obj0014E238 {
    char pad[0x20];
    void* m_p;
    void Run(int x);
};

void Obj0014E238::Run(int x)
{
    func_00171690(m_p, x, 1);
}
