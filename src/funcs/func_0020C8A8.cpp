struct Script_0020C8A8 {
    char pad0[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" int func_00100030(int n);
extern "C" void func_001E7200(void* s, unsigned int name, int value);
extern "C" void func_001E72B0(void* s, unsigned int name, float value);

bool Cmd_Random_0020C8A8(void* params, Script_0020C8A8* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0xA1DC81F9, &name, 0);
    if (func_001E8708(params, 0xA5F054F4)) {
        int a = 0;
        int b = 0;
        func_001E7DE8(params, 0x174841BC, &a, 0);
        func_001E7DE8(params, 0x8E411006, &b, 0);
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        void* out = script->m_params;
        func_001E7200(out, name, a + func_00100030(b - a + 1));
    } else {
        int steps = 1000;
        func_001E7DE8(params, 0x022CF075, &steps, 0);
        float a = 0.0f;
        float b = 0.0f;
        func_001E7EB0(params, 0x174841BC, &a, 0);
        func_001E7EB0(params, 0x8E411006, &b, 0);
        void* out = script->m_params;
        func_001E72B0(out, name, a + (float)func_00100030(steps) * (b - a) / (float)(steps - 1));
    }
    return true;
}
