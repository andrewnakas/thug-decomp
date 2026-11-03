struct Track_001DC7B0 {
    int m0;
    int m4;
    int m8;
    char m_pad[0x18 - 0xC];
};

extern Track_001DC7B0 D_003ECCD0[128];
extern int D_0038E0AC;
extern int D_0038E0B8;
extern int D_0038E0B0;
extern float D_0038E0A8;
extern "C" bool func_001DC418();
extern "C" void func_001E2038();

void func_001DC7B0()
{
    if (func_001DC418()) {
        return;
    }
    D_0038E0AC = 0;
    D_0038E0B8 = 0;
    for (int i = 127; i >= 0; i--) {
        D_003ECCD0[i].m8 = 0;
    }
    func_001E2038();
    D_0038E0B0 = 0;
    D_0038E0A8 = 1020.0f;
}
