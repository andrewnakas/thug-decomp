extern void* D_0038C608;
extern "C" void func_00187B48(void* a, unsigned int name);

struct C_00203EE0 {
    char m_pad[0x320];
    int m320;
    void Run();
};

void C_00203EE0::Run()
{
    func_00187B48(D_0038C608, m320 == 1 ? 0xE17B231A : 0x967C138C);
}
