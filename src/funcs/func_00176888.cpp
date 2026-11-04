extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern int D_0039401C;
extern int D_00394000;
extern int D_00394018;
extern unsigned char* D_00394038;
extern int D_0038BF80;
extern unsigned char D_00393F9C[3];
extern unsigned char D_00393F9F;
extern unsigned char D_00393FA0[2];
extern char D_00361010[];
extern float D_003876D4;
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void PutB(unsigned char v)
{
    *D_00394038++ = v;
}

extern "C" void func_00176888(short* v)
{
    if (!D_0039401C) {
        unsigned char* p = D_00394274;
        D_00394284 = 8;
        D_0039428C = 3;
        D_00394288 = p;
        Put((((unsigned short)D_00394000 + (unsigned short)D_00394280) & 0x3FF) | 0x6A00C000);
        D_00394038 = D_00394274;
        if (D_0038BF80) {
            PutB(D_00393F9C[0]);
            PutB(D_00393F9C[1]);
            PutB(D_00393F9C[2]);
            PutB(D_00393F9F);
            PutB(D_00393FA0[0]);
            PutB(D_00393FA0[1]);
        }
        D_00394274 = (unsigned char*)(D_00394038 + D_00394018 * 3);
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
    D_00393F9C[0] = D_00393F9F;
    D_00393F9C[1] = D_00393FA0[0];
    D_00393F9C[2] = D_00393FA0[1];
    unsigned char a = (int)((v[0] + 0.5f) * D_003876D4);
    D_00393F9F = a;
    int b = (int)((v[1] + 0.5f) * D_003876D4);
    D_00393FA0[0] = b;
    if ((unsigned char)b == 0) {
        D_00393F9F = 0xFF;
        D_00393FA0[0] = 1;
    }
    D_00393FA0[1] = -D_00393FA0[0] - D_00393F9F;
    *D_00394038++ = D_00393F9F;
    *D_00394038++ = D_00393FA0[0];
    *D_00394038++ = D_00393FA0[1];
    D_00394000++;
}
