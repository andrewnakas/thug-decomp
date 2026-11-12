/* cflags: -fno-gcse */
/* fuzzy: 97.4 */
extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern unsigned int D_0039429C;
extern char D_00360D08[];
extern char D_1D0[];
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

static inline void Pair(unsigned short a, unsigned short b)
{
    ((unsigned short*)D_00394274)[0] = a;
    ((unsigned short*)D_00394274)[1] = b;
    D_00394274 += 4;
}

extern "C" int func_0017ED88(void* tex);   /* width */
extern "C" int func_0017EDA8(void* tex);   /* height */

/* VIF packet for a (optionally textured) sprite: header, optional UV quad, colours, then six positions */
extern "C" void func_00169E68(void* tex, float* v0, float* v1, float* v2, float* v3, float* v4, unsigned int col0, unsigned int col1)
{
    int k;
    if (tex) {
        Put(0x01000103);
        D_0039429C = 3;
        Unpack(0x6C, 1, D_00394280, 1);
        func_00164328(0x412, 3, 0, 0x15C, 1, (unsigned int)D_1D0 >> 3);
    } else {
        Put(0x01000102);
        D_0039429C = 2;
        Unpack(0x6C, 1, D_00394280, 1);
        func_00164328(0x41, 2, 0, 0x4D, 1, (unsigned int)D_1D0 >> 3);
    }
    k = 1;
    if (tex) {
        int w = func_0017ED88(tex) << 4;
        int h = func_0017EDA8(tex) << 4;
        D_00394284 = 0x10;
        D_0039428C = 2;
        D_00394288 = D_00394274;
        Put((((unsigned short)D_00394280 + 1) & 0x3FF) | 0x65004000);
        Pair(w >> 1, h >> 1);
        Pair(0, 0);
        Pair(w, 0);
        Pair(0, h);
        Pair(w, h);
        Pair(0, 0);
        End();
        k = 2;
    }
    D_00394288 = D_00394274;
    D_00394284 = 8;
    D_0039428C = 4;
    Put((((unsigned short)D_00394280 + k) & 0x3FF) | 0x6E004000);
    Word(col0);
    Word(col1);
    Word(col1);
    Word(col1);
    Word(col1);
    Word(col1);
    End();
    k++;
    Put(0x05000001);
    D_00394288 = D_00394274;
    D_0039428C = 4;
    D_00394284 = 0x20;
    Put((((unsigned short)D_00394280 + k) & 0x3FF) | 0x6C000000);
    Vec4(v0, 0);
    Vec4(v1, 0);
    Vec4(v2, 0);
    Vec4(v3, 0);
    Vec4(v4, 0);
    Vec4(v1, 0);
    End();
    Put(0x05000000);
    func_001643B8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
}
