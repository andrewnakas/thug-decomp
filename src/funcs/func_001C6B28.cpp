struct Mgr_001C6B28 {
    char m_pad[0x24];
    void* m24;
};

extern Mgr_001C6B28* D_0038FC78;
extern int D_00390EF8;

extern "C" bool func_00263BD8(void* set, unsigned int name);
extern "C" void* func_001E53A0(unsigned int name, int a);
extern "C" void func_00263C18(void* set, void* item);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

extern "C" float func_001C6B28()
{
    float v;
    if (func_00263BD8(D_0038FC78->m24, 0x9C8C6DF1)) {
        void* set = D_0038FC78->m24;
        func_00263C18(set, func_001E53A0(0x9C8C6DF1, 0));
        D_00390EF8 = 1;
        float half;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0xA5E2DA58, &half, 1);
        v = half * 0.5f;
    } else {
        float full;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0xA5E2DA58, &full, 1);
        v = full;
    }
    return v;
}
