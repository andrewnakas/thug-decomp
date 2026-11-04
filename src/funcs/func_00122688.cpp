struct Info_00122688 {
    int m0[8];
    int m20;
    float m24;
    float m28;
    float m2C;
    int m30;
    int m34;
};

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E7720(void* s, unsigned int id, void* arr);
extern "C" void func_001E72B0(void* s, unsigned int name, float f);
extern "C" void func_001E7200(void* s, unsigned int name, int v);

extern "C" int func_00122688(Info_00122688* info, void* s)
{
    void* a = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(a, 2, 1);
    func_001E90A8(a, 0, info->m0[0]);
    func_001E90A8(a, 1, info->m0[1]);
    void* b = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(b, 2, 1);
    func_001E90A8(b, 0, info->m0[2]);
    func_001E90A8(b, 1, info->m0[3]);
    void* c = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(c, 2, 1);
    func_001E90A8(c, 0, info->m0[4]);
    func_001E90A8(c, 1, info->m0[5]);
    void* d = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(d, 2, 1);
    func_001E90A8(d, 0, info->m0[6]);
    func_001E90A8(d, 1, info->m0[7]);
    func_001E7720(s, 0x08BF1D3F, a);
    func_001E7720(s, 0xB0B44396, b);
    func_001E7720(s, 0x7F03932C, c);
    func_001E7720(s, 0x0E7EC187, d);
    if (info->m20) {
        func_001E72B0(s, 0x6E94F918, info->m24);
        func_001E72B0(s, 0xE4F130F4, info->m28);
        func_001E72B0(s, 0x949BC47B, info->m2C);
    }
    func_001E7200(s, 0x73E5BAD0, info->m30);
    func_001E7200(s, 0x0AB21AF0, info->m34);
    return 1;
}
