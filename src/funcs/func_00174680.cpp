extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_00360FD0[];
extern char D_310[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));
extern "C" void func_00164490(int a);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

extern "C" void func_00174680()
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
        func_00103F28(D_00360FD0);
        func_00334148(1);
    }
    if (D_00394290) {
        func_00164490(1);
        Put(0x05000000);
        Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = D_00394280;
    } else {
        D_00394274 -= 0x18;
    }
    unsigned int id = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (id != 3 && id != 0 && id != 4) {
        *(unsigned short*)D_00394278 = (D_00394274 - D_00394278 - 8) >> 4;
    }
}
