extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" void func_001F1188(void* script, unsigned int v);

bool func_0021ABF0(void* params, void* script)
{
    unsigned int v = 0x1CA1FF20;
    func_001E8398(params, 0, &v, 0);
    func_001F1188(script, v);
    return true;
}
