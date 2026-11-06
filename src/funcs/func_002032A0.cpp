extern "C" void* func_00203278(void* a);
extern "C" bool func_001E7EB0(void* p, void* name, float* out, int required);
extern "C" float func_001E5318(void* a, void* b);

extern "C" float func_002032A0(void* a, void* b)
{
    float f;
    if (func_001E7EB0(func_00203278(a), a, &f, 0))
        return f;
    return func_001E5318(a, b);
}
