extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" bool func_0023D488(void* target, int value);

bool Script_002413A0(void* params)
{
    void* target = func_00240850();
    int value;
    func_001E8398(params, 0xA1DC81F9, &value, 1);
    return func_0023D488(target, value);
}
