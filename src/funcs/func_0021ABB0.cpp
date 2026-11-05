extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001F1138(void* obj, unsigned int v);

extern "C" bool func_0021ABB0(void* params, void* obj)
{
    unsigned int v;
    func_001E8398(params, 0, &v, 1);
    func_001F1138(obj, v);
    return true;
}
