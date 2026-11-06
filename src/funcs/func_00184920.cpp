extern void* D_0038C7B0;
extern "C" void func_00189750(void* p, int a, unsigned int b, int c, int d, int e);
struct Obj_00184920 {
    char pad[0x18];
    int m18;
    void Run(int a, int d);
};

void Obj_00184920::Run(int a, int d)
{
    func_00189750(D_0038C7B0, a, 0xFFFFFFFF, m18, d, 1);
}
