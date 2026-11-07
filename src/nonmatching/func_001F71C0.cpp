/* fuzzy: 64.3 */
typedef int qword_001F71C0 __attribute__((mode(TI)));

struct Tag_001F71C0 {
    unsigned long lo;
    unsigned long hi;
};

struct GifTag_001F71C0 {
    unsigned long NLOOP : 15;
    unsigned long EOP : 1;
    unsigned long pad16 : 16;
    unsigned long id : 14;
    unsigned long PRE : 1;
    unsigned long PRIM : 11;
    unsigned long FLG : 2;
    unsigned long NREG : 4;
    unsigned long REGS0 : 4;
    unsigned long REGS1 : 4;
    unsigned long REGS2 : 4;
    unsigned long REGS3 : 4;
    unsigned long REGS4 : 4;
    unsigned long REGS5 : 4;
    unsigned long REGS6 : 4;
    unsigned long REGS7 : 4;
    unsigned long REGS8 : 4;
    unsigned long REGS9 : 4;
    unsigned long REGS10 : 4;
    unsigned long REGS11 : 4;
    unsigned long REGS12 : 4;
    unsigned long REGS13 : 4;
    unsigned long REGS14 : 4;
    unsigned long REGS15 : 4;
};

struct Packet_001F71C0 {
    unsigned int* pCurrent;
    qword_001F71C0* pBase;
    qword_001F71C0* pDmaTag;
    unsigned long* pGifTag;
};

struct Env_001F71C0 {
    char pad0[0x18];
    long m18;
    char pad20[0x50 - 0x20];
    union {
        qword_001F71C0 q;
        GifTag_001F71C0 tag;
    } m50;
    char m60[0x20];
    long m80;
};

extern Env_001F71C0 D_003F2F40;
extern const Tag_001F71C0 D_00366448;

extern "C" int func_0031B468(int ch);
extern "C" void func_00344B98(void* draw, short psm, short w, short h, short ztest, short zpsm);
extern "C" int func_0031BF20(int mode);
extern "C" int func_003312D8(int mode, int timeout);
extern "C" int func_00344D80(void* draw);
extern "C" void func_00322EE0(Packet_001F71C0* pkt, qword_001F71C0* buf);
extern "C" void func_00322EF0(Packet_001F71C0* pkt);
extern "C" void func_00323068(Packet_001F71C0* pkt, unsigned int opt1, unsigned int opt2, unsigned int flag);
extern "C" void func_003230F8(Packet_001F71C0* pkt, qword_001F71C0 tag);
extern "C" void func_003231B8(Packet_001F71C0* pkt, unsigned int addr, unsigned long data);
extern "C" void func_00323110(Packet_001F71C0* pkt);
extern "C" void func_00322F00(Packet_001F71C0* pkt);
extern "C" int func_0031B750(int ch, void* addr);

void func_001F71C0(int r, int g, int b, int w, int h)
{
    union {
        qword_001F71C0 q;
        Tag_001F71C0 t;
    } tag;
    tag.t = D_00366448;
    Env_001F71C0* env = &D_003F2F40;
    if (env->m18 == 0) {
        return;
    }
    int ch = func_0031B468(2);
    env->m50.q = 0;
    env->m50.tag.NLOOP = 8;
    env->m50.tag.EOP = 1;
    env->m50.tag.NREG = 1;
    env->m50.tag.REGS0 = 0xE;
    func_00344B98(env->m60, 0, w, ((h + 31) / 32 + (h / 2 + 31) / 32) * 64, 0, 0);
    env->m80 = 0;
    func_0031BF20(0);
    func_003312D8(0, 0);
    func_00344D80(&env->m50);

    Packet_001F71C0 pkt;
    qword_001F71C0 buf[6];
    func_00322EE0(&pkt, buf);
    func_00322EF0(&pkt);
    func_00323068(&pkt, 0, 0, 0);
    func_003230F8(&pkt, tag.q);
    func_003231B8(&pkt, 0, 6);
    func_003231B8(&pkt, 1, (unsigned long)r | ((unsigned long)g << 8) | ((unsigned long)b << 16));
    func_003231B8(&pkt, 5, 0);
    func_003231B8(&pkt, 5, 0xB4002D00UL);
    func_00323110(&pkt);
    func_00322F00(&pkt);
    func_0031BF20(0);
    func_003312D8(0, 0);
    func_0031B750(ch, pkt.pBase);
    func_003312D8(0, 0);
}
