extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);

void func_001A56D0(void* params, float* out)
{
    if (func_001E7EB0(params, 0, out, 0)) {
        if (func_001E8708(params, 0xF414A5EA))
            *out *= 12.0f;
        else if (!func_001E8708(params, 0x7644323B))
            *out *= 17.6f;
    }
}
