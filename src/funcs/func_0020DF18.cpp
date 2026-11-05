extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001E00E0(float v);

extern "C" bool func_0020DF18(void* params, void* script)
{
    float v = 100.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_001E00E0(v);
    return true;
}
