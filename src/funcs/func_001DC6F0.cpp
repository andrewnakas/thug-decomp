struct Slot_001DC6F0 {
    int m0;
    int m4;
    char m_pad[0x3C - 0x8];
};

extern Slot_001DC6F0 D_003EC2F8[42];
extern "C" bool func_001DC418();

struct Mgr_001DC6F0 {
    int m0;
    int m4;
    Mgr_001DC6F0();
};

extern "C" void func_001E2068(Mgr_001DC6F0* self);

Mgr_001DC6F0::Mgr_001DC6F0()
{
    if (func_001DC418()) {
        return;
    }
    m4 = 0;
    func_001E2068(this);
    for (int i = 0; i < 42; i++) {
        D_003EC2F8[i].m0 = 0;
        D_003EC2F8[i].m4 = 0;
    }
}
