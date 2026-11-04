extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern int D_0039401C;
extern int D_00394000;
extern int D_00394018;
extern unsigned short* D_0039403C;
extern int D_0038BF80;
extern unsigned short D_00393F88[2];
extern unsigned short D_00393F8C[2];
extern char D_00361010[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void PutS(unsigned short v)
{
    *D_0039403C++ = v;
}

extern "C" void func_001763F8(short* v, int sx, int sy)
{
    if (!D_0039401C) {
        unsigned char* p = D_00394274;
        D_00394284 = 0x10;
        D_0039428C = 2;
        D_00394288 = p;
        Put((((unsigned short)D_00394000 + (unsigned short)D_00394280) & 0x3FF) | 0x6500C000);
        D_0039403C = (unsigned short*)D_00394274;
        if (D_0038BF80) {
            PutS(D_00393F88[0]);
            PutS(D_00393F88[1]);
            PutS(D_00393F8C[0]);
            PutS(D_00393F8C[1]);
        }
        D_00394274 = (unsigned char*)(D_0039403C + D_00394018 * 2);
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
            func_00103F28(D_00361010);
            func_00334148(1);
        }
    }
    PutS((int)(v[0] * (float)sx * (1.0f / 4096.0f)) + 0x2000);
    PutS((int)(v[1] * (float)sy * (1.0f / 4096.0f)) + 0x2000);
    D_00393F88[0] = D_00393F8C[0];
    D_00393F8C[0] = D_0039403C[-2];
    D_00393F88[1] = D_00393F8C[1];
    D_00393F8C[1] = D_0039403C[-1];
    D_00394000++;
}
