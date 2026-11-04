extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern int D_0038882C;
extern int D_0038C104;
extern void* D_0038C10C;
extern void* D_0038C110;
extern "C" void func_0017F488();
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_0017F410(void* p);

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

static inline void Close()
{
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}

extern "C" void func_0017F1C8()
{
    func_0017F488();
    Tag(0x10000000, 0);
    func_001645F8(0, 0, 0);
    Reg(5, 8);
    int pal = D_0038882C == 1;
    Reg((pal ? 0x6C00 : 0x7000) | ((long)(pal ? 0x7200 : 0x7000) << 32), 0x18);
    Reg(0x5000D, 0x47);
    func_001646D0(0);
    Close();
    func_0017F410(D_0038C110);
    if (D_0038C104) {
        func_0017F410(D_0038C10C);
    }
    Tag(0x10000000, 0);
    func_001645F8(0, 0, 0);
    Reg(0x50000, 0x47);
    func_001646D0(0);
    Close();
    if (!D_0038C104) {
        func_0017F410(D_0038C10C);
    }
}
