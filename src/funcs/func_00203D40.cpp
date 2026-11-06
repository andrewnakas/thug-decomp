extern "C" void* func_00203278();
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" void func_00203B20(void* self, void* p);

extern "C" void func_00203D40(void* self, unsigned int name)
{
    void* p = 0;
    if (!func_001E8180(func_00203278(), name, &p, 0))
        p = func_001E5548(name, 0);
    func_00203B20(self, p);
}
