/* fuzzy: 95.7 */
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
extern "C" void func_00334148(int a) __attribute__((noreturn));
extern "C" void func_001643B8(int a);
extern "C" int func_0017ED88(void* t);
extern "C" int func_0017EDA8(void* t);
extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline unsigned int Code(int cmd, int num, unsigned short addr, int usn)
{
    return ((usn << 14) | (addr & 0x3FF)) & 0xFFFF | ((cmd << 24) | (num << 16));
}

static inline void Unpack(int cmd, int num, unsigned short addr, int usn)
{
    Put(Code(cmd, num, addr, usn));
    D_00394290 = num;
}

static inline void Word(unsigned int v)
{
    *(unsigned int*)D_00394274 = v;
    D_00394274 += 4;
}

static inline void Half2(unsigned short a, unsigned short b)
{
    ((unsigned short*)D_00394274)[0] = a;
    ((unsigned short*)D_00394274)[1] = b;
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

extern "C" void func_00168F58(void* tex, float* a, float* b, float* d, float* c,
                              unsigned int e, unsigned int f, unsigned int h, unsigned int g)
{
    int n = 0;
    if (tex) {
        Put(0x01000103);
        D_0039429C = 3;
        Unpack(0x6C, 1, D_00394280 + n, 1);
        func_00164328(0x413, 3, 0, 0x15C, 1, (unsigned int)D_1D0 >> 3);
    } else {
        Put(0x01000102);
        D_0039429C = 2;
        Unpack(0x6C, 1, D_00394280 + n, 1);
        func_00164328(0x41, 2, 0, 0x4C, 1, (unsigned int)D_1D0 >> 3);
    }
    n++;
    if (tex) {
        int w = func_0017ED88(tex) << 4;
        int ht = func_0017EDA8(tex) << 4;
        D_00394284 = 0x10;
        D_0039428C = 2;
        D_00394288 = D_00394274;
        Put(Code(0x65, 0, D_00394280 + n, 1));
        Half2(0, 0);
        Half2(w, 0);
        Half2(0, ht);
        Half2(w, ht);
        End();
        n++;
    }
    D_00394284 = 8;
    D_0039428C = 4;
    D_00394288 = D_00394274;
    Put(Code(0x6E, 0, D_00394280 + n, 1));
    Word(e);
    Word(f);
    Word(g);
    Word(h);
    End();
    Put(0x05000001);
    D_00394288 = D_00394274;
    D_00394284 = 0x20;
    D_0039428C = 4;
    Put(Code(0x6C, 0, D_00394280 + ++n, 0));
    Vec4(a, 0);
    Vec4(b, 0);
    Vec4(c, 0);
    Vec4(d, 0);
    End();
    Put(0x05000000);
    func_001643B8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
}
