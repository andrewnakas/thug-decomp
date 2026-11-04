struct Info_001228A8 {
    int m0[8];
    int m20;
    float m24;
    float m28;
    float m2C;
    int m30;
    int m34;
};

extern "C" int func_001E8248(void* s, unsigned int name, void** out, int req);
extern "C" int func_001E9270(void* arr, int i);
extern "C" int func_001E7EB0(void* s, unsigned int name, float* out, int req);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);

extern "C" int func_001228A8(Info_001228A8* info, void* s)
{
    void* a = 0;
    void* b = 0;
    void* c = 0;
    void* d = 0;
    func_001E8248(s, 0x08BF1D3F, &a, 0);
    if (!a)
        return 0;
    info->m0[0] = func_001E9270(a, 0);
    info->m0[1] = func_001E9270(a, 1);
    func_001E8248(s, 0xB0B44396, &b, 0);
    if (!b)
        return 0;
    info->m0[2] = func_001E9270(b, 0);
    info->m0[3] = func_001E9270(b, 1);
    func_001E8248(s, 0x7F03932C, &c, 0);
    if (!c)
        return 0;
    info->m0[4] = func_001E9270(c, 0);
    info->m0[5] = func_001E9270(c, 1);
    func_001E8248(s, 0x0E7EC187, &d, 0);
    if (!d)
        return 0;
    info->m0[6] = func_001E9270(d, 0);
    info->m0[7] = func_001E9270(d, 1);
    info->m20 = func_001E7EB0(s, 0x6E94F918, &info->m24, 0);
    info->m20 = func_001E7EB0(s, 0xE4F130F4, &info->m28, 0) && info->m20;
    info->m20 = func_001E7EB0(s, 0x949BC47B, &info->m2C, 0) && info->m20;
    info->m30 = 0;
    info->m34 = 0;
    func_001E7DE8(s, 0x73E5BAD0, &info->m30, 0);
    func_001E7DE8(s, 0x0AB21AF0, &info->m34, 0);
    return 1;
}
