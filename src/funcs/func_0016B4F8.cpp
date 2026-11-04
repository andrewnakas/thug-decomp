extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern unsigned int D_0039429C;
extern char D_00360D08[];
extern char D_200[];
extern char D_310[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a);
extern "C" void func_001643B8(int a);
extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Unpack(int cmd, int num, unsigned short addr, int usn)
{
    Put(((usn << 14) | (addr & 0x3FF)) & 0xFFFF | ((cmd << 24) | (num << 16)));
    D_00394290 = num;
}

static inline void Word(unsigned int v)
{
    *(unsigned int*)D_00394274 = v;
    D_00394274 += 4;
}

static inline void Vec4(float* v, unsigned int w)
{
    float x = v[0] * 16.0f;
    float y = v[1] * 16.0f;
    float z = v[2] * 16.0f;
    ((unsigned int*)D_00394274)[0] = (int)x;
    ((unsigned int*)D_00394274)[1] = (int)y;
    ((unsigned int*)D_00394274)[2] = (int)z;
    ((unsigned int*)D_00394274)[3] = w;
    D_00394274 += 16;
}

static inline void End()
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
    D_00394290 = ((D_00394274 - D_00394288) - 4) * 8 / (D_0039428C * D_00394284);
    while (D_00394274 < end) {
        *D_00394274++ = 0;
    }
    if (D_00394290 == 0) {
        D_00394274 -= 4;
    } else if (D_00394290 < 0x100) {
        D_00394288[2] = D_00394290;
    } else if (D_00394290 == 0x100) {
        D_00394288[2] = 0;
    } else {
        func_00103F28(D_00360D08);
        func_00334148(1);
    }
}

extern "C" void func_0016B4F8(float* a, float* b, unsigned int c, unsigned int d)
{
    Put(0x01000102);
    D_0039429C = 2;
    Unpack(0x6C, 1, D_00394280, 1);
    func_00164328(0x51, 2, 0, 0x49, 1, (unsigned int)D_200 >> 3);
    D_00394284 = 8;
    D_0039428C = 4;
    D_00394288 = D_00394274;
    Put((((unsigned short)D_00394280 + 1) & 0x3FF) | 0x6E004000);
    Word(c);
    Word(d);
    End();
    Put(0x05000001);
    D_00394288 = D_00394274;
    D_00394284 = 0x20;
    D_0039428C = 4;
    Put((((unsigned short)D_00394280 + 2) & 0x3FF) | 0x7C000000);
    Vec4(a, 0);
    Vec4(b, 0);
    End();
    Put(0x05000000);
    func_001643B8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
}
