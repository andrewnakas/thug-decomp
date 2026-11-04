struct Ctrl_001AEB48 {
    char pad[0x6C];
    int m6C;
};

extern "C" unsigned int func_0010FC30();
extern "C" int func_001AE978(void* self, int a, int b);

struct C_001AEB48 {
    char pad[0x20];
    Ctrl_001AEB48* m20;
    char pad24[0xA44];
    int mA68;
    char padA6C[0x8A0];
    int m130C;
    int m1310;
    unsigned int m1314;
    unsigned int m1318;
    int m131C;
    int m1320[10];
    int m1348[10];
    int m1370;
    int m1374;
    void Update();
};

void C_001AEB48::Update()
{
    if (!m130C)
        return;
    if (!m1310) {
        unsigned int start = m1318;
        if (m1314 < func_0010FC30() - start) {
            m130C = 0;
            return;
        }
    }
    if (m1370) {
        if (m20->m6C) {
            mA68 = 1;
            if (!func_001AE978(this, m1370, m1374))
                mA68 = 0;
            if (!m130C)
                return;
        } else {
            mA68 = 0;
        }
    }
    for (int i = 0; i < m131C; i++) {
        if (func_001AE978(this, m1320[i], m1348[i]))
            mA68 = 0;
        if (!m130C)
            return;
    }
}
