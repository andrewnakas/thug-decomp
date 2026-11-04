extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" bool func_0023C9D8(void* target, int value);

bool Script_00240F08(void* params)
{
    void* target = func_00240850();
    int value;
    func_001E8398(params, 0xA1DC81F9, &value, 1);
    return func_0023C9D8(target, value);
}
