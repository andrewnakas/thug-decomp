struct Comp_00120BD8 {
    char pad0[0x48];
    int m_params[2];
};

extern Comp_00120BD8* D_00389520;
extern void* D_0038951C;
extern "C" int func_001E89F0(void* params, unsigned int name, void** out, int req);
extern "C" int func_0011DE78(void* p, void* s);

extern "C" int func_00120BD8()
{
    void* s = 0;
    if (func_001E89F0(D_00389520->m_params, 0x812684EF, &s, 0)) {
        return func_0011DE78(D_0038951C, s);
    }
    return 0;
}
