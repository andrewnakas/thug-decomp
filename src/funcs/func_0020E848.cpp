extern void* D_0038E0A0;

extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001DD030(void* screen, const char* text, int flags, float time, float alpha, float scale);

bool func_0020E848(void* params)
{
    const char* text;
    if (func_001E8870(params, 0, &text, 1)) {
        float alpha;
        float time;
        float scale;
        scale = 100.0f;
        alpha = 100.0f;
        time = 0.0f;
        func_001E7EB0(params, 0xD8604126, &alpha, 0);
        if (func_001E7EB0(params, 0xFF2020EC, &time, 0)) {
            time *= 12.0f;
        }
        func_001E7EB0(params, 0xF6A36814, &scale, 0);
        int flags = func_001E8708(params, 0x389129E4) != 0;
        if (func_001E8708(params, 0xCF15C120)) {
            flags |= 4;
        } else if (func_001E8708(params, 0x8B87176F)) {
            flags |= 0x10;
        }
        func_001DD030(D_0038E0A0, text, flags, time, alpha, scale);
    }
    return true;
}
