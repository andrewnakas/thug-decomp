extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_0022BEF8(float v);

extern "C" int func_00213160(void* params)
{
    float v = 120.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_0022BEF8(v);
    return 1;
}
