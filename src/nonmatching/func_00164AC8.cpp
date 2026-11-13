/* fuzzy: 85.5 */
// GS FINISH interrupt handler: acknowledges the event, advances the list of drawn packets to the next one
// that has data for the current buffer and restarts the VIF1 / GIF transfers that were waiting for it.

struct Packet_00164AC8 {
    Packet_00164AC8* m_next;
    int m_04[3];
    unsigned int m_gifTag[2];       // 0x10
    unsigned int m_vifTag[2];       // 0x18
    int m_20[2];
    int m_count[2];                 // 0x28
    int m_30[4];
    unsigned int m_start;           // 0x40
    unsigned int m_end;             // 0x44
};

extern Packet_00164AC8* D_003942E8;
extern Packet_00164AC8* D_003942EC;
extern int D_00394094;
extern int D_00393F34;
extern int D_00393F30;

#define D1_CHCR (*(volatile unsigned int*)0x10009000)
#define D1_QWC  (*(volatile unsigned int*)0x10009020)
#define D1_TADR (*(volatile unsigned int*)0x10009030)
#define D2_CHCR (*(volatile unsigned int*)0x1000A000)
#define D2_QWC  (*(volatile unsigned int*)0x1000A020)
#define D2_TADR (*(volatile unsigned int*)0x1000A030)
#define GS_CSR    (*(volatile unsigned long*)0x12001000)
#define GS_IMR    (*(volatile unsigned long*)0x12001010)
#define GS_BUSDIR (*(volatile unsigned long*)0x12001080)

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

static inline void KickVif1_00164AC8(Packet_00164AC8* p)
{
    D1_QWC = 0;
    D1_TADR = p->m_vifTag[D_00394094 ? 0 : 1];
    D1_CHCR = 0x145;
    D_00393F34 = 0;
}

static inline void KickGif_00164AC8(Packet_00164AC8* p)
{
    D2_QWC = 0;
    D2_TADR = p->m_gifTag[D_00394094 ? 0 : 1];
    D2_CHCR = 0x105;
    D_00393F30 = 0;
}

int func_00164AC8(int)
{
    GS_IMR = 0xFF00;
    GS_CSR = (GS_CSR & ~0x30FL) | 1;
    GS_BUSDIR &= ~1L;
    if (D_003942EC) {
        for (D_003942EC = D_003942EC->m_next; D_003942EC; D_003942EC = *(Packet_00164AC8**)D_003942EC) {
            if (D_003942EC->m_count[D_00394094 ? 0 : 1] != 0) {
                break;
            }
        }
        Packet_00164AC8* cur = D_003942EC;
        if (cur) {
            if (D_00393F30) {
                Packet_00164AC8* next = D_003942E8;
                if (cur == next) {
                    KickGif_00164AC8(cur);
                    D_00393F34 = 2;
                } else {
                    KickVif1_00164AC8(cur);
                    if (!(cur->m_start < next->m_end && next->m_start < cur->m_end)) {
                        KickGif_00164AC8(next);
                    }
                }
            } else if (D_003942E8) {
                D_00393F34 = 1;
            } else {
                KickVif1_00164AC8(cur);
            }
        }
    }
    GS_IMR = 0xFE00;
    ExitHandler();
    return 0;
}
