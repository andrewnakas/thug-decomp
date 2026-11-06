/* fuzzy: 90.8 */
extern unsigned char* D_00394274;
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);

struct Tex_00168D98 {
    char pad[0x28];
    long m28;
    long m30;
};

static inline void AddReg_00168D98(long data, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (int)data;
    p[1] = (int)(data >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

static inline void AddTag_00168D98(int n)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = n | 0x04000000;
    D_00394274 = (unsigned char*)(p + 1);
}

extern "C" void func_00168D98(Tex_00168D98* tex, long alpha, int a, int b)
{
    func_001645F8(a, 0, 0);
    AddReg_00168D98(alpha, 0x42);
    if (tex) {
        AddReg_00168D98(tex->m28, 6);
        AddReg_00168D98(tex->m30, 0x14);
    }
    func_001646D0(0);
    int n = 2;
    if (!b)
        n = 1;
    AddTag_00168D98(n);
}
