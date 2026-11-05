extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_001F1240(void* script, int v);

bool func_0021AC88(void* params, void* script)
{
    int v = 0;
    func_001E8398(params, 0, &v, 0);
    func_001F1240(script, v);
    return true;
}
