extern void* D_0038E0A0;
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" void func_001DC958(void* p, float v);

bool func_0020F218(void* params, void* script)
{
    float v = 1020.0f;
    func_001E7EB0(params, 0, &v, 0);
    if (v <= 0.0f)
        return false;
    func_001DC958(D_0038E0A0, v * 12.0f);
    return true;
}
