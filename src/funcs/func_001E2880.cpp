// Interrupt-time callback: ORs the event's bits into the pending mask and raises the pending flag.

struct Event_001E2880 {
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
};

extern volatile int D_0038E298;
extern volatile int D_0038E29C;

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

void func_001E2880(Event_001E2880* e)
{
    D_0038E298 |= e->m_10;
    D_0038E29C = 1;
    ExitHandler();
}
