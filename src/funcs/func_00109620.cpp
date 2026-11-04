extern "C" void func_001E8870(void*, int, int*, int);
extern "C" int func_001E8708(void*, unsigned int);
extern "C" void func_00109088(void*, int, int, int, int);
extern void* D_00388A44;

bool func_00109620(void* params, void* script)
{
    int name;
    func_001E8870(params, 0, &name, 1);
    int n = name;
    void* fs = D_00388A44;
    int a = func_001E8708(params, 0x90E07C79);
    int b = func_001E8708(params, 0x3D92465E);
    int c = func_001E8708(params, 0xA44C770F);
    func_00109088(fs, n, a, b, c);
    return true;
}
