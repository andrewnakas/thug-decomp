extern "C" void func_00171848(void* p, int x, int k);

struct Obj0014E2B8 {
    char pad[0x20];
    void* m_p;
    void Run(int x);
};

void Obj0014E2B8::Run(int x)
{
    func_00171848(m_p, x, 1);
}
