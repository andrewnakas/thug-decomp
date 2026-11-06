extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001DFF20(int a, float t);

extern "C" bool func_0020ED90(void* params, void* script)
{
    int a = 0;
    if (func_001E8398(params, 0, &a, 0)) {
        float t = -1.0f;
        func_001E7EB0(params, 0xF6A36814, &t, 0);
        func_001DFF20(a, t);
        return true;
    }
    return false;
}
