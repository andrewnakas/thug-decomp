extern "C" void* func_00240850();
extern "C" bool func_001E7C80(void* params, unsigned int name, int* out, int required);
extern "C" void func_002407B0(void* target, int value);

bool Script_00243888(void* params)
{
    void* target = func_00240850();
    int value;
    func_001E7C80(params, 0, &value, 1);
    func_002407B0(target, value);
    return true;
}
