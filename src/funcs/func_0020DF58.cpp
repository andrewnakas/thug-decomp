extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" void func_001E0188(float v);

extern "C" int func_0020DF58(void* params)
{
    float v = 100.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_001E0188(v);
    return 1;
}
