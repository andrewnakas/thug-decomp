struct Rec_0026F938 {
    char m[0x24];
};

extern "C" void func_0026FC00(Rec_0026F938* r, int a);

struct Stats_0026F938 {
    int m0;
    Rec_0026F938 m4;
    Rec_0026F938 m28;
    Rec_0026F938 m4C;
    Rec_0026F938 m70;
    Rec_0026F938 m94;
    Rec_0026F938 mB8;
    Rec_0026F938 mDC;
    Rec_0026F938 m100;
    Rec_0026F938 m124;
    Rec_0026F938 m148;
    Rec_0026F938 m16C;
    Rec_0026F938 m190;
    Rec_0026F938 m1B4;
    Rec_0026F938 m1D8;
    Rec_0026F938 m1FC;
    Rec_0026F938 m220;
    int m244[11];
    int m270;
    void Reset();
};

void Stats_0026F938::Reset()
{
    func_0026FC00(&m4, 0);
    func_0026FC00(&m28, 0);
    func_0026FC00(&m4C, 0);
    func_0026FC00(&m70, 0);
    func_0026FC00(&m94, 0);
    func_0026FC00(&mB8, 0);
    func_0026FC00(&mDC, 0);
    func_0026FC00(&m100, 0);
    func_0026FC00(&m124, 0);
    func_0026FC00(&m148, 0);
    func_0026FC00(&m190, 0);
    func_0026FC00(&m16C, 0);
    func_0026FC00(&m1D8, 0);
    func_0026FC00(&m1B4, 0);
    func_0026FC00(&m1FC, 0);
    func_0026FC00(&m220, 0);
    m244[0] = 0;
    m244[1] = 0;
    m244[2] = 0;
    m244[3] = 0;
    m244[4] = 0;
    m244[5] = 0;
    m244[6] = 0;
    m244[7] = 0;
    m244[8] = 0;
    m244[9] = 0;
    m244[10] = 0;
    m270 = 0;
}
