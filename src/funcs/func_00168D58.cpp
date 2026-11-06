extern char D_3A8[];
extern char D_003E13C0[];
extern "C" void func_00164E48(int a, unsigned int n);
extern "C" void func_00164F48(void* p);
extern "C" void func_00164EB8(int a);

extern "C" void func_00168D58()
{
    func_00164E48(0, (unsigned int)D_3A8 >> 3);
    func_00164F48(D_003E13C0);
    func_00164EB8(0);
}
