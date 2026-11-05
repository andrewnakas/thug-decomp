extern void* D_00392068;
extern "C" int func_002A49B8(void* a);
extern "C" void func_002A4A58(void* a, int b);

void Run_0022EE88()
{
    void* p = D_00392068;
    func_002A4A58(p, func_002A49B8(p));
}
