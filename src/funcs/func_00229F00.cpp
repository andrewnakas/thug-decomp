extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" void func_001E9270(void* a, void* b);

void Get_00229F00(void* params, void* b)
{
    void* p = 0;
    func_001E8248(params, 0x2E7D5EE7, &p, 0);
    func_001E9270(p, b);
}
