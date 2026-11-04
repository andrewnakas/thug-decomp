extern "C" void func_00118158(void* p, int x, int k);

struct Obj00144DF0 {
    char pad[0x4];
    void* m_p;
    void Run(int x);
};

void Obj00144DF0::Run(int x)
{
    func_00118158(m_p, x, 1);
}
