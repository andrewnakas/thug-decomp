// Interrupt-time callback: latches two words of the event and raises the pending flags.

struct Event_001E2840 {
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
};

extern volatile int D_00394104;
extern volatile int D_00394108;
extern volatile int D_0038E298;
extern volatile int D_0038E29C;
extern volatile int D_00394100;

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

void func_001E2840(Event_001E2840* e)
{
    D_00394104 = e->m_10;
    D_00394108 = e->m_0C;
    D_0038E298 |= e->m_14;
    D_0038E29C = 1;
    D_00394100 = 1;
    ExitHandler();
}
