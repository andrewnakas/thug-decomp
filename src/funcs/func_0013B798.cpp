extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" void func_0013B578(float f);
extern "C" void func_0013B580(float f);
extern "C" void func_0013B588(float f);

bool Cmd_0013B798(void* params, void* script)
{
    float a;
    float b;
    if (func_001E7EB0(params, 0x33AA4915, &a, 0))
        func_0013B578(a);
    if (func_001E7EB0(params, 0xA0A0DB70, &b, 0))
        func_0013B580(b);
    if (func_001E7EB0(params, 0x774B6931, &b, 0))
        func_0013B588(b);
    return true;
}
