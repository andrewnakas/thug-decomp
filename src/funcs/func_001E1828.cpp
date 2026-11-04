extern "C" void func_001E23B0(int cmd, int addr, void* data);
extern int D_0038E1DC;
extern void* D_0038E1D8;

struct Pkt_001E1828 {
    int m_0;
    int m_4;
    short m_8;
    short m_A;
    int m_C;
    int m_10;
};

void func_001E1828(void)
{
    Pkt_001E1828 p;
    p.m_8 = 0;
    p.m_A = 0;
    p.m_C = 0;
    p.m_10 = 0;
    p.m_4 = 0;
    D_0038E1DC = 0;
    D_0038E1D8 = 0;
    func_001E23B0(0x8010, 0xB80, 0);
    func_001E23B0(0x8010, 0xC80, D_0038E1D8);
    func_001E23B0(0x8030, 0x1900, 0);
    func_001E23B0(0x8030, 0x1B00, 0);
    func_001E23B0(0x8130, 0, &p);
}
