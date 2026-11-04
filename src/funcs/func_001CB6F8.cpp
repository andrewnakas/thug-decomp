extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);

static inline float GetParam_001CB6F8(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

float func_001CB6F8()
{
    float base = GetParam_001CB6F8(0xDE86132E);
    float scale = GetParam_001CB6F8(0x7201AD48);
    return base - scale * GetParam_001CB6F8(0xA8C13E74);
}
