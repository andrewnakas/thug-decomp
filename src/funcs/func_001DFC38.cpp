struct Slot_001DFC38 {
    char m_data[0xC80];
    int m_C80;
    long m_C88;
    long m_C90;
    long m_C98;
    long m_CA0;
    int m_CA8;
};

struct Chan_001DFC38 {
    int m_0;
    int m_4;
    char m_pad[0x20];
};

extern int D_003F2220[3];
extern Slot_001DFC38 D_003F0898[2];
extern Chan_001DFC38 D_003EE8E0[3];
extern int D_0038E148;
extern float D_0038E134;
extern float D_0038E138;

extern "C" bool func_001DED20();
extern "C" bool func_001DED40();
extern "C" void func_001E33F8();
extern "C" int func_001E53A0(unsigned int key, int a);

void Audio_001DFC38_Init()
{
    for (int i = 2; i >= 0; i--) {
        D_003F2220[i] = 0;
    }
    if (func_001DED20() && func_001DED40()) {
        return;
    }
    func_001E33F8();
    D_0038E148 = 1;
    D_0038E134 = (float)func_001E53A0(0xABD4A575, 0);
    if (D_0038E134 == 0.0f) {
        D_0038E134 = 50.0f;
    }
    D_0038E138 = (float)func_001E53A0(0x73F8E03B, 0);
    if (D_0038E138 == 0.0f) {
        D_0038E138 = 100.0f;
    }
    for (int i = 0; i < 2; i++) {
        D_003F0898[i].m_C80 = 0;
        D_003F0898[i].m_C88 = 0;
        D_003F0898[i].m_C90 = 0;
        D_003F0898[i].m_C98 = 0;
        D_003F0898[i].m_CA0 = 0;
        D_003F0898[i].m_CA8 = 1;
    }
    for (int i = 0; i < 3; i++) {
        D_003F2220[i] = 0;
        D_003EE8E0[i].m_0 = 0;
        D_003EE8E0[i].m_4 = 0;
    }
}
