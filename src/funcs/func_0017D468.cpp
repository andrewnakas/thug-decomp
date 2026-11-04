struct Node_0017D468;

extern Node_0017D468* D_003942A0;
extern Node_0017D468* D_0039427C;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned char* D_00394288;
extern "C" void func_001617A0(Node_0017D468* n);
extern "C" void func_00164530(int a, int b, int c, int d, int e);
extern "C" void func_001647B0(int reg, unsigned long v);
extern "C" void func_00164570(int a);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

extern "C" void func_0017D468(int x0, int y0, int x1, int y1, unsigned int color)
{
    Node_0017D468* cur = D_003942A0;
    if (D_0039427C != cur) {
        func_001617A0(cur);
    }
    Tag(0x10000000, 0);
    Put(0x11000000);
    unsigned char* end = (unsigned char*)((((int)D_00394274 + 3) & ~0xF) + 0xC);
    while (D_00394274 < end) {
        *D_00394274++ = 0;
    }
    D_00394288 = D_00394274;
    Put(0x50000000);
    unsigned long z = (unsigned long)0xFFFFFF << 32;
    func_00164530(0xE, 1, 0, 0x46, 1);
    func_001647B0(0x42, 0x44);
    func_001647B0(1, color);
    func_001647B0(5, (unsigned short)x0 | ((unsigned long)(unsigned short)y0 << 16) | z);
    func_001647B0(5, (unsigned short)x1 | ((unsigned long)(unsigned short)y1 << 16) | z);
    func_00164570(1);
    unsigned char* p = D_00394274;
    unsigned char* aligned = (unsigned char*)(((int)p + 0xF) & ~0xF);
    for (; p < aligned; p++) {
        *p = 0;
        D_00394274 = p + 1;
    }
    *(unsigned short*)D_00394288 = (D_00394274 - D_00394288 - 4) / 16;
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}
