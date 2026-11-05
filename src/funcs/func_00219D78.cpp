extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001DF108(int v);

extern "C" bool func_00219D78(void* params, void* script)
{
    int v;
    func_001E7DE8(params, 0, &v, 1);
    func_001DF108(v);
    return true;
}
