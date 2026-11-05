extern void* D_0038E0A0;
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001DD5A0(void* p, float v);

extern "C" bool func_0020DED8(void* params, void* script)
{
    float v = 100.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_001DD5A0(D_0038E0A0, v);
    return true;
}
