extern unsigned char* D_00394274;
extern unsigned char* D_00394288;
extern unsigned int D_00394284;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern char D_00360900[];
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00334148(int code) __attribute__((noreturn));
extern "C" void func_001643B8(unsigned int eop);

void func_001646D0(unsigned int eop)
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
    D_00394290 = (unsigned int)((D_00394274 - D_00394288 - 4) * 8) / (D_0039428C * D_00394284);
    while (D_00394274 < end)
        *D_00394274++ = 0;
    if (D_00394290 == 0) {
        D_00394274 -= 4;
    } else if (D_00394290 < 0x100) {
        D_00394288[2] = D_00394290;
    } else if (D_00394290 == 0x100) {
        D_00394288[2] = 0;
    } else {
        func_00103F28(D_00360900);
        func_00334148(1);
    }
    func_001643B8(eop);
}
