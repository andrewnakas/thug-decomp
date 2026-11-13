/* fuzzy: 91.0 */
/* Downloads a rectangle of GS local memory to main memory (host <- local transfer): builds a small VIF/GIF
   packet (BITBLTBUF, TRXPOS, TRXREG, FINISH, TRXDIR = 1), sends it over the VIF1 DMA channel, reverses the
   bus direction and DMAs the image into dst, then restores the bus. The game's two `sync` barriers after the
   CHCR writes are inline asm and are not expressible here. */
typedef int qword __attribute__((mode(TI)));

struct Packet_00181E38 {
    unsigned int* m_cur;
    unsigned int* m_base;
    int m8;
    int pad[5];
};

extern char D_00361498[];
extern char D_003614E0[];
extern qword D_0034EC90;

extern "C" void func_00103F28(const char* fmt, int line, const char* file);
extern "C" void func_00334148(int code);
extern "C" void func_003231E0(Packet_00181E38* p, void* buf);
extern "C" void func_003231F0(Packet_00181E38* p);
extern "C" void func_00323258(Packet_00181E38* p, unsigned int w);
extern "C" void func_00323270(Packet_00181E38* p, unsigned long d);
extern "C" void func_00323200(Packet_00181E38* p);
extern "C" void func_0031BF20(int mode);

#define VIF1_STAT (*(volatile unsigned int*)0x10003C00)
#define VIF1_FIFO (*(volatile qword*)0x10005000)
#define D1_CHCR (*(volatile unsigned int*)0x10009000)
#define D1_MADR (*(volatile unsigned int*)0x10009010)
#define D1_QWC (*(volatile unsigned int*)0x10009020)
#define GS_CSR (*(volatile unsigned long*)0x12001000)
#define GS_BUSDIR (*(volatile unsigned long*)0x12001040)

void func_00181E38(void* dst, short sbp, short psm, short ssax, short ssay, short w, short h, short width)
{
    Packet_00181E38 pkt;
    qword buf[10];
    int qwc;

    if (psm == 0)
        qwc = (w * h * 32) >> 7;
    else if (psm == 1)
        qwc = (w * h * 24) >> 7;
    else if (psm == 2)
        qwc = (w * h * 16) >> 7;
    else if (psm == 0x13)
        qwc = (w * h * 8) >> 7;
    else
        qwc = (w * h * 4) >> 7;
    int sbw = width >> 6;
    if (qwc > 0x7FFF) {
        func_00103F28(D_00361498, 0x195, D_003614E0);
        func_00334148(0);
    }
    if (sbw <= 0)
        sbw = 1;

    func_003231E0(&pkt, buf);
    func_003231F0(&pkt);
    func_00323258(&pkt, 0);
    func_00323258(&pkt, 0x06008000);
    func_00323258(&pkt, 0x13000000);
    func_00323258(&pkt, 0x50000006);
    func_00323270(&pkt, 0x1000000000008005);
    func_00323270(&pkt, 0xE);
    func_00323270(&pkt, ((long)sbw << 16) | (long)sbp | ((long)psm << 24));
    func_00323270(&pkt, 0x50);
    func_00323270(&pkt, (long)ssax | (ssay << 16));
    func_00323270(&pkt, 0x51);
    func_00323270(&pkt, (long)w | ((long)h << 32));
    func_00323270(&pkt, 0x52);
    func_00323270(&pkt, 0);
    func_00323270(&pkt, 0x61);
    func_00323270(&pkt, 1);
    func_00323270(&pkt, 0x53);
    func_00323200(&pkt);

    GS_CSR = 2;
    func_0031BF20(0);
    D1_QWC = 7;
    D1_MADR = (unsigned int)pkt.m_base & 0x0FFFFFFF;
    D1_CHCR = 0x101;
    while (D1_CHCR & 0x100)
        ;
    while (!(GS_CSR & 2))
        ;
    VIF1_STAT = 0x800000;
    GS_BUSDIR = 1;
    func_0031BF20(0);
    D1_QWC = qwc;
    D1_MADR = (unsigned int)dst & 0x0FFFFFFF;
    D1_CHCR = 0x100;
    while (D1_CHCR & 0x100)
        ;
    VIF1_STAT = 0;
    GS_BUSDIR = 0;
    GS_CSR = 2;
    VIF1_FIFO = D_0034EC90;
}
