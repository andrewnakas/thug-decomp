extern "C" bool func_001E8180(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_00203B20(void* p, unsigned int v);

extern "C" void func_00203DB0(void* p, unsigned int name, void* params)
{
    unsigned int v = 0;
    func_001E8180(params, name, &v, 0);
    func_00203B20(p, v);
}
