extern unsigned int* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern unsigned int D_0039429C;
extern char D_1E0[];
extern char D_310[];
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_001643B8(int a);
extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d);

static inline void Put(unsigned int v)
{
    unsigned int* p = D_00394274;
    *p = v;
    D_00394274 = p + 1;
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = p + 3;
}

static inline void Unpack(int cmd, int num, unsigned short addr, int usn, unsigned short flg)
{
    Put((((flg << 15) | (usn << 14)) | (addr & 0x3FF)) & 0xFFFF | ((cmd << 24) | (num << 16)));
    D_00394290 = num;
}

static inline void Word(unsigned int v)
{
    *D_00394274 = v;
    D_00394274++;
}

static inline void Pair(float a, float b)
{
    D_00394274[0] = (int)(a * 4096.0f);
    D_00394274[1] = (int)(b * 4096.0f);
    D_00394274 += 2;
}

static inline void Vec4(float* v, unsigned int w)
{
    float x = v[0] * 16.0f;
    float y = v[1] * 16.0f;
    float z = v[2] * 16.0f;
    D_00394274[0] = (int)x;
    D_00394274[1] = (int)y;
    D_00394274[2] = (int)z;
    D_00394274[3] = w;
    D_00394274 += 4;
}

extern "C" void func_00169A78(float* a, float* b, float* c, int d, int e, int f, int flg,
                              float f0, float f1, float f2, float f3, float f4, float f5)
{
    func_001645F8(flg, 0, 0);
    Reg(0, 0x7F);
    func_001646D0(0);
    Unpack(0x6C, 1, D_00394280, 1, flg);
    func_00164328(0x412, 3, 0, 0x5C, 1, ((unsigned int)D_1E0 >> 3) | 0x3000);
    Put(0x01000103);
    D_0039429C = 3;
    Unpack(0x64, 3, (unsigned short)D_00394280 + 1, 1, flg);
    Pair(f0, f1);
    Pair(f2, f3);
    Pair(f4, f5);
    Unpack(0x6E, 3, (unsigned short)D_00394280 + 2, 1, flg);
    Word(d);
    Word(e);
    Word(f);
    Put(0x05000001);
    Unpack(0x6C, 3, (unsigned short)D_00394280 + 3, 0, flg);
    Vec4(a, 0xC000);
    Vec4(b, 0xC000);
    Vec4(c, 0);
    Put(0x05000000);
    func_001643B8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
}
