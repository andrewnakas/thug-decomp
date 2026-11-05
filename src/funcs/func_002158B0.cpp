extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" void func_0010FAA8(float v);

bool func_002158B0(void* params, void* script)
{
    float v = 1.0f;
    func_001E7EB0(params, 0, &v, 0);
    func_0010FAA8(v);
    return true;
}
