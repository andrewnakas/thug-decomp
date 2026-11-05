extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_00270E88(void* self, float v);

void Load_002709C8(void* self, void* params)
{
    float v;
    if (func_001E7EB0(params, 0xF1A99B27, &v, 0))
        func_00270E88(self, v);
}
