/* fuzzy: 91.0 */
// DMA-end interrupt handler: advances the list of queued packets to the next one that has data for the
// current buffer, then (if a kick is pending) starts the VIF1 transfer of the current packet and, unless the
// two packets' ranges overlap, the GIF transfer of the next one.

struct Packet_00164920 {
    Packet_00164920* m_next;
    int m_04[3];
    unsigned int m_gifTag[2];       // 0x10
    unsigned int m_vifTag[2];       // 0x18
    int m_20[2];
    int m_count[2];                 // 0x28
    int m_30[4];
    unsigned int m_start;           // 0x40
    unsigned int m_end;             // 0x44
};

extern Packet_00164920* D_003942E8;
extern Packet_00164920* D_003942EC;
extern int D_00394094;
// Flags shared with the main loop: volatile (the game never fills a branch delay slot with their stores,
// e.g. 0x00164A4C `sw $zero, D_00393F30` / 0x00164A50 `b` / 0x00164A54 `nop`).
extern volatile int D_00393F34;
extern volatile int D_00393F30;

#define D1_CHCR (*(volatile unsigned int*)0x10009000)
#define D1_QWC  (*(volatile unsigned int*)0x10009020)
#define D1_TADR (*(volatile unsigned int*)0x10009030)
#define D2_CHCR (*(volatile unsigned int*)0x1000A000)
#define D2_QWC  (*(volatile unsigned int*)0x1000A020)
#define D2_TADR (*(volatile unsigned int*)0x1000A030)

// Leave an interrupt handler: the EE requires sync.l before re-enabling interrupts.
static inline void ExitHandler()
{
    __asm__ __volatile__("sync.l\n\tei");
}

static inline void KickVif1_00164920()
{
    D1_QWC = 0;
    D1_TADR = D_003942EC->m_vifTag[D_00394094 ? 0 : 1];
    D1_CHCR = 0x145;
    D_00393F34 = 0;
}

int func_00164920(int)
{
    if (D_003942E8) {
        for (D_003942E8 = D_003942E8->m_next; D_003942E8; D_003942E8 = *(Packet_00164920**)D_003942E8) {
            if (D_003942E8->m_count[D_00394094 ? 0 : 1] != 0) {
                break;
            }
        }
        Packet_00164920* next = D_003942E8;
        if (next) {
            if (D_00393F34) {
                D1_QWC = 0;
                D1_TADR = D_003942EC->m_vifTag[D_00394094 ? 0 : 1];
                D1_CHCR = 0x145;
                D_00393F34 = 0;
                Packet_00164920* cur = D_003942EC;
                if (!(cur->m_start < next->m_end && next->m_start < cur->m_end)) {
                    D2_QWC = 0;
                    D2_TADR = next->m_gifTag[D_00394094 ? 0 : 1];
                    D2_CHCR = 0x105;
                    D_00393F30 = 0;
                } else {
                    D_00393F30 = 1;
                }
            } else {
                D_00393F30 = 1;
            }
        } else if (D_00393F34) {
            KickVif1_00164920();
        }
    }
    ExitHandler();
    return 0;
}
