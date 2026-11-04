extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern int D_0039401C;
extern int D_00394000;
extern int D_00394018;
extern unsigned short* D_00394030;
extern int D_0038BF80;
extern unsigned short D_00393F90[3];
extern unsigned short D_00393F96[3];
extern "C" float sqrtf(float);
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
    *D_00394030++ = v;
}

extern "C" void func_00176620(short* v)
{
    if (!D_0039401C) {
        unsigned char* p = D_00394274;
        D_00394284 = 0x10;
        D_0039428C = 3;
        D_00394288 = p;
        Put((((unsigned short)D_00394000 + (unsigned short)D_00394280) & 0x3FF) | 0x69008000);
        D_00394030 = (unsigned short*)D_00394274;
        if (D_0038BF80) {
            PutS(D_00393F90[0]);
            PutS(D_00393F90[1]);
            PutS(D_00393F90[2]);
            PutS(D_00393F96[0]);
            PutS(D_00393F96[1]);
            PutS(D_00393F96[2]);
        }
        D_00394274 = (unsigned char*)(D_00394030 + D_00394018 * 3);
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
    PutS(v[0]);
    PutS(v[1]);
    float x = v[0];
    float y = v[1];
    short z = (int)sqrtf(1073676289.0f - x * x - y * y);
    if (v[0] & 1) {
        z = -z;
    }
    PutS(z);
    D_00393F90[0] = D_00393F96[0];
    D_00393F96[0] = D_00394030[-3];
    D_00393F90[1] = D_00393F96[1];
    D_00393F96[1] = D_00394030[-2];
    D_00393F90[2] = D_00393F96[2];
    D_00393F96[2] = D_00394030[-1];
    D_00394000++;
}
