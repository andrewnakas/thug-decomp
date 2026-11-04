extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern int D_00388814;

struct C_001AB648 {
    int m_pad[4];
    void* GetTarget(void* params);
};

void* C_001AB648::GetTarget(void* params)
{
    void* r = 0;
    if (D_00388814 == 4) {
        if (!func_001E8180(params, 0xCE42EE1A, &r, 0)) func_001E8180(params, 0xE594F0A2, &r, 1);
    } else if (D_00388814 == 5) {
        if (!func_001E8180(params, 0xCB0E600C, &r, 0)) func_001E8180(params, 0xE594F0A2, &r, 1);
    } else {
        func_001E8180(params, 0xE594F0A2, &r, 1);
    }
    return r;
}
