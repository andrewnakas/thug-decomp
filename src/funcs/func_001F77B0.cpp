// VSync-start interrupt handler for movie playback: records the current GS field and, when a decoded frame
// is ready, uploads it to the frame buffer of the field being shown next and switches the display to it.

struct Frame_001F77B0 {
    int m_state;
};

extern volatile int D_0038EAB0;      // current field (GS CSR bit 13)
extern volatile int D_0038EAA4;
extern volatile int D_0038EAA8;
extern volatile int D_0038EAB4;
extern int D_0038E320;
extern int D_00394118;
extern int D_0038EAAC;
extern unsigned char D_003F3090[];
extern unsigned char D_003F2FA0[];
extern unsigned char D_003F2F40[];

extern "C" void* func_0031B468(int a);
extern "C" int func_003312D8(int a, int b);
extern "C" Frame_001F77B0* func_001F5190(int a);
extern "C" void func_00345560(unsigned int addr, int w, int h, short field);
extern "C" void func_00345100(void* a, int b);
extern "C" void func_0031B750(void* a, void* b);

#define GS_CSR (*(volatile unsigned long*)0x12001000)

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

int func_001F77B0(int)
{
    void* ctx = func_0031B468(2);
    D_0038EAB0 = (GS_CSR >> 13) & 1;
    if (D_0038EAA4) {
        D_0038EAA8++;
        D_0038EAB4 = func_003312D8(1, 0);
        if (D_0038EAB4 == 0) {
            Frame_001F77B0* f = func_001F5190(D_0038E320 + 0x673700);
            if (f == 0) {
                D_00394118++;
                ExitHandler();
                return 0;
            }
            func_00345560(((unsigned int)((D_0038EAB0 & 1) ? D_003F3090 : D_003F2FA0) & 0x0FFFFFFF) | 0x20000000,
                          0x800, 0x800, D_0038EAB0 ^ 1);
            if (D_0038EAB0 == 0 && f->m_state == 2) {
                func_00345100(D_003F2F40, 0);
                func_003312D8(0, 0);
                func_0031B750(ctx, (char*)f + 0x40);
                f->m_state = 1;
            } else if (D_0038EAB0 == 1 && f->m_state == 1) {
                func_00345100(D_003F2F40, 1);
                func_003312D8(0, 0);
                func_0031B750(ctx, (char*)f + 0x26740);
                f->m_state = 0;
                D_0038EAAC = 1;
            }
        }
    }
    ExitHandler();
    return 0;
}
