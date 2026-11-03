extern "C" void* func_00240850();
extern "C" void func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" void func_0023E238(void* target, int value);

bool Script_00241CC0(void* params)
{
    int value;
    func_001E8398(params, 0xA1DC81F9, &value, 1);
    func_0023E238(func_00240850(), value);
    return true;
}
