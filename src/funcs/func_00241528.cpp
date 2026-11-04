extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0023D578(void* target, int value);

bool Script_00241528(void* params)
{
    void* target = func_00240850();
    int value;
    func_001E7DE8(params, 0, &value, 1);
    func_0023D578(target, value);
    return true;
}
