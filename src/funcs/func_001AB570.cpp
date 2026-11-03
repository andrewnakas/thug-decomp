struct C_001AB570 {
    int m_pad[7];
    int m1C;
    int m20[608];
    int m9A0[3];
    int m9AC[22];
    int mA04[22];
    int mA5C;
    int mA60[2];
    int mA68;
    int mA6C;
    int mA70;
    int mA74;
    int mA78[511];
    int m1274;
    int m1278;
    int m127C[11];
    int m12A8;
    int m12AC[17];
    int m12F0;
    int m12F4[6];
    int m130C;
    int m1310;
    int m1314;
    int m1318;
    int m131C;
    int m1320[20];
    int m1370;
    int m1374;
    int m1378;
    void Reset();
};

extern "C" void func_001AB720(C_001AB570* self);
extern "C" void func_001AB788(C_001AB570* self);
extern "C" void func_001AEE68(C_001AB570* self);
extern "C" void func_001AB758(C_001AB570* self);

void C_001AB570::Reset()
{
    m1C = 0;
    mA5C = 0;
    mA68 = 0;
    mA70 = -1;
    mA74 = -1;
    func_001AB720(this);
    m1274 = 0;
    m1278 = 0;
    func_001AB788(this);
    m12A8 = 0;
    func_001AEE68(this);
    m12F0 = 0;
    m130C = 0;
    m1310 = 0;
    m1314 = 0;
    m1318 = 0;
    m131C = 0;
    m1370 = 0;
    m1374 = 0;
    func_001AB758(this);
    for (int i = 2; i >= 0; i--) m9A0[i] = 0;
    for (int j = 0; j < 22; j++) {
        mA04[j] = 0;
        m9AC[j] = 0;
    }
    m1378 = 1;
}
