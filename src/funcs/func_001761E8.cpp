extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern int D_0039401C;
extern int D_00394000;
extern int D_00394018;
extern float* D_00394024;
extern int D_0038BF80;
extern int D_00393F78;
extern int D_00393F7C;
extern int D_00393F80;
extern int D_00393F84;
extern char D_00361010[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void PutData(int v)
{
    int* p = (int*)D_00394024;
    *p = v;
    D_00394024 = (float*)(p + 1);
}

static inline void PutF(float v)
{
    *D_00394024++ = v;
}

extern "C" void func_001761E8(short* v)
{
    if (!D_0039401C) {
        Put(0x20000000);
        Put(0xE0);
        unsigned char* p = D_00394274;
        D_00394288 = p;
        D_00394284 = 0x20;
        D_0039428C = 2;
        Put((((unsigned short)D_00394000 + (unsigned short)D_00394280) & 0x3FF) | 0x74008000);
        D_00394024 = (float*)D_00394274;
        if (D_0038BF80) {
            PutData(D_00393F78);
            PutData(D_00393F7C);
            PutData(D_00393F80);
            PutData(D_00393F84);
        }
        D_00394274 = (unsigned char*)(D_00394024 + D_00394018 * 2);
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
    PutF(v[0] * (1.0f / 4096.0f));
    PutF(v[1] * (1.0f / 4096.0f));
    D_00393F78 = D_00393F80;
    D_00393F80 = *(int*)(D_00394024 - 2);
    D_00393F7C = D_00393F84;
    D_00393F84 = *(int*)(D_00394024 - 1);
    D_00394000++;
}
