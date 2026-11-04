extern void* D_00392808;
extern "C" void func_002C52B0(void* p);
extern "C" void func_002C5278(void* p);
extern "C" void* func_002C0368();
extern "C" void func_002BD4B8(void* p, int v);
extern "C" void func_002C5328(void* p);

extern "C" bool func_002CA750()
{
    func_002C52B0(D_00392808);
    func_002C5278(D_00392808);
    func_002BD4B8(func_002C0368(), 1);
    func_002C5328(D_00392808);
    return true;
}
