extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);

void func_00236F80(void* self, int index)
{
    void* params = func_001E6978(func_001190D0(8));
    func_001E7360(params, 0x33124D2E, index + 0x1E55886E);
    func_001E7360(params, 0x6E7C7BA7, index + 0x44727DAE);
    func_001E7360(params, 0x6D02989C, index + 0xF4D3A70E);
    func_001F0210(0xC890E875, params, 0, 0, 0);
    if (params)
        func_001E6AE8(params, 3);
}
