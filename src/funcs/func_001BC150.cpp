extern "C" void func_001BC020(void* self, void* params, int bit, int mask, unsigned int nameOn, unsigned int nameOff, int* slot);

struct C_001BC150 {
    int m_pad[7];
    int m1C;
    int m20;
    int m24;
    int m28[9];
    int m4C[9];
    int m70[9];
    int m94[9];
    int mB8[9];
    int mDC[9];
    int m100[9];
    int m124[9];
    int m148[9];
    int m16C[9];
    int m190[9];
    int m1B4[9];
    int m1D8[9];
    int m1FC[9];
    void Setup(void* params);
};

void C_001BC150::Setup(void* params)
{
    m1C = m20;
    m20 = 0;
    func_001BC020(this, params, 6, 0x40, 0x5C8FAA09, 0xB27804A2, m28);
    func_001BC020(this, params, 7, 0x80, 0xD26ADAE9, 0xAEF7DFD3, m4C);
    func_001BC020(this, params, 5, 0x20, 0xB4F2ADBA, 0xC86FA880, m70);
    func_001BC020(this, params, 4, 0x10, 0x0EDBBC2B, 0xC8ABF89C, m94);
    func_001BC020(this, params, 9, 0x200, 0xB069B600, 0xE5AAE06B, m190);
    func_001BC020(this, params, 11, 0x800, 0xA93DBBD0, 0xFCFEEDBB, m1B4);
    func_001BC020(this, params, 8, 0x100, 0x7F695A77, 0x7B684919, m1D8);
    func_001BC020(this, params, 10, 0x400, 0x42717176, 0xBBBEF674, m1FC);
    func_001BC020(this, params, 12, 0x1000, 0xC6547217, 0x28A3DCBC, mB8);
    func_001BC020(this, params, 14, 0x4000, 0x5F5D23AD, 0xB1AA8D06, mDC);
    func_001BC020(this, params, 16, 0x10000, 0x285A133B, 0xC6ADBD90, m100);
    func_001BC020(this, params, 13, 0x2000, 0x12154DC8, 0xFCE2E363, m124);
    func_001BC020(this, params, 15, 0x8000, 0x8B1C1C72, 0x65EBB2D9, m148);
    func_001BC020(this, params, 17, 0x20000, 0xFC1B2CE4, 0x12EC824F, m16C);
    func_001BC020(this, params, 22, 0x400000, 0x33947317, 0xF5E437A0, 0);
    func_001BC020(this, params, 23, 0x800000, 0xF8DE049B, 0x3EAE402C, 0);
    func_001BC020(this, params, 24, 0x1000000, 0xAC7F105A, 0x55B09758, 0);
}
