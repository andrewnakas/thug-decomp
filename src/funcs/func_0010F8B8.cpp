// Interrupt handler: counts ticks in a 32-bit and a 64-bit counter.

extern volatile int D_00388D7C;
extern volatile long D_00388D88;

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

int func_0010F8B8(int)
{
    D_00388D7C++;
    D_00388D88++;
    ExitHandler();
    return 0;
}
