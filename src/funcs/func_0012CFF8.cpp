struct Obj12CFF8 {
    char m_pad[0x2C];
    virtual ~Obj12CFF8();
};

extern Obj12CFF8* D_00389A30;
extern unsigned int D_00389A34;

extern "C" void func_0012CFF8()
{
    if (D_00389A34 >= 2) {
        D_00389A34--;
        return;
    }
    if (D_00389A30) {
        delete D_00389A30;
    }
    D_00389A30 = 0;
    D_00389A34 = 0;
}
