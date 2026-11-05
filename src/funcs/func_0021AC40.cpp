extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001F1230(void* obj, unsigned int v);

extern "C" bool func_0021AC40(void* params, void* obj)
{
    unsigned int v = 0;
    func_001E8398(params, 0, &v, 0);
    func_001F1230(obj, v);
    return true;
}
