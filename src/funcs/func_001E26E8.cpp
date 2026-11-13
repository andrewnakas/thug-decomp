// Interrupt-time callback for a two-port status event: 0x80F0 clears the busy flag; 0x8040 with a 0x17xx
// sub-code latches the new state of port (code & 1) and updates its pressed/released/changed masks.

struct Event_001E26E8 {
    char pad00[0x10];
    unsigned short m_code;
    unsigned short m_sub;
    int m_state;
};

extern volatile int D_00394340;
extern volatile int D_00394338[2];
extern volatile int D_0038E1F8[2];
extern volatile int D_003940F8[2];
extern volatile int D_003940F0[2];
extern int D_0038E200[2];
extern int D_0038E208[2];
extern int D_003940E8[2];
extern "C" long func_0010FA80();

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

void func_001E26E8(Event_001E26E8* e)
{
    unsigned short code = e->m_code;
    if (code == 0x80F0) {
        D_00394340 = 0;
    } else if (code == 0x8040) {
        unsigned short sub = e->m_sub;
        int port = sub & 1;
        if ((sub & 0xFF00) == 0x1700) {
            D_00394338[port] = e->m_state;
            D_0038E1F8[port] = func_0010FA80();
            D_003940F0[port] &= ~D_003940F8[port];
            int cleared = D_003940F8[port];
            D_003940F8[port] = 0;
            int changed = D_0038E200[port] & (D_00394338[port] | ~D_003940F0[port]);
            D_003940E8[port] &= ~cleared;
            D_0038E208[port] &= ~(D_00394338[port] | ~D_003940F0[port]);
            D_00394338[port] &= ~changed;
            D_0038E200[port] = changed;
        }
    }
    ExitHandler();
}
