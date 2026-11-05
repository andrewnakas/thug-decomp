extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_0022BEF0(float v);

extern "C" bool func_00213120(void* params, void* script)
{
    float v = 400.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_0022BEF0(v);
    return true;
}
