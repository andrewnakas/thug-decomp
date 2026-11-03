struct Track_001DC988 {
    int m0;
    int m4;
    int m8;
    char m_pad[0x18 - 0xC];
};

extern Track_001DC988 D_003ECCD0[128];
extern int D_0038E0AC;
extern int D_0038E0B8;
extern "C" bool func_001DC418();
extern "C" void func_001E1E50();

void func_001DC988()
{
    if (func_001DC418()) {
        return;
    }
    func_001E1E50();
    D_0038E0AC = 0;
    D_0038E0B8 = 0;
    for (int i = 127; i >= 0; i--) {
        D_003ECCD0[i].m8 = 0;
    }
}
