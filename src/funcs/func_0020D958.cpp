extern int D_003F5790[];
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_00183348(unsigned int name);
extern "C" unsigned int func_0010FC30();
extern "C" int func_0033EBE0(float f);

bool Cmd_0020D958(void* params, void* script)
{
    float secs = 1.0f;
    unsigned int name = 0;
    func_001E7EB0(params, 0x906B67BA, &secs, 0);
    if (func_001E8398(params, 0, &name, 0)) {
        int idx = func_00183348(name);
        unsigned int t = func_0010FC30();
        int* p = &D_003F5790[idx];
        *p = func_0033EBE0((float)t + secs * 1000.0f);
    }
    return true;
}
