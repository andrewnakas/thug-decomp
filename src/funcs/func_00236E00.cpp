struct Params_00236E00;

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_00236E00* func_001E6978(void* mem);
extern "C" void func_001E7360(Params_00236E00* p, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int script, Params_00236E00* p, int a, int b, int c);
extern "C" void func_001E6AE8(Params_00236E00* p, int flags);

static inline void Delete_00236E00(Params_00236E00* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

void func_00236E00(void* self, unsigned int base)
{
    Params_00236E00* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x33124D2E, base + 0x1E55886E);
    func_001E7360(p, 0x6E7C7BA7, base + 0x44727DAE);
    func_001E7360(p, 0x6D02989C, base + 0xF4D3A70E);
    func_001F0210(0x3BD51FE5, p, 0, 0, 0);
    Delete_00236E00(p);
}
