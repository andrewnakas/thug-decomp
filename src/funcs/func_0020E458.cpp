extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" void func_001E4C38(const char* s);

extern "C" bool func_0020E458(void* params, void* script)
{
    const char* s;
    if (!func_001E8870(params, 0, &s, 1))
        return false;
    func_001E4C38(s);
    return true;
}
