struct Pkt_001E1968 {
    int m0;
    int m4;
    short m8;
    short mA;
    int mC;
    int m10;
};

extern int D_0038E1D8;
extern int D_0038E1DC;
extern int D_00351D08[];
extern "C" void func_001E1828();
extern "C" void func_001E1928();
extern "C" int func_001E23B0(int, unsigned short, int);

void Call_001E1968(int type, int on, float depth)
{
    if (depth == 0.0f) {
        D_0038E1D8 = 0;
        if (on) {
            func_001E1828();
        }
        return;
    }
    func_001E1928();
    Pkt_001E1968 p;
    p.m8 = 0x3FFF;
    p.mA = 0x3FFF;
    p.mC = 30;
    p.m10 = 200;
    p.m4 = D_00351D08[type];
    D_0038E1D8 = (int)(depth * 163.83f);
    func_001E23B0(0x8130, 0, (int)&p);
    func_001E23B0(0x8070, 2, 1);
    if (on) {
        func_001E23B0(0x8010, 0xB80, D_0038E1D8);
        func_001E23B0(0x8010, 0xC80, D_0038E1D8);
        D_0038E1DC = D_0038E1D8;
    }
    func_001E23B0(0x8030, 0x1900, 0x1FFFFF);
    func_001E23B0(0x8030, 0x1B00, 0x1FFFFF);
}
