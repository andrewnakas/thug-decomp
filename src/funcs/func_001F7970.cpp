// Interrupt handler: services one pending request flagged by D_0038EAAC.

extern volatile int D_0038EAAC;
extern int D_0038E320;
extern "C" void func_001F51F8(int arg);

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

int func_001F7970(int)
{
    if (D_0038EAAC) {
        func_001F51F8(D_0038E320 + 0x673700);
        D_0038EAAC = 0;
    }
    ExitHandler();
    return 0;
}
