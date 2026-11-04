typedef int qword __attribute__((mode(TI)));

struct Vec_001A6810 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw = 1.0f)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct C_001A6810 {
    int m_pad0[7];
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m_pad3C[5];
    Vec_001A6810 m50;
    Vec_001A6810 m60;
    Vec_001A6810 m70;
    int m_pad80[4];
    Vec_001A6810 m90;
    Vec_001A6810 mA0;
    Vec_001A6810 mB0;
    Vec_001A6810 mC0;
    Vec_001A6810 mD0;
    Vec_001A6810 mE0;
    Vec_001A6810 mF0;
    Vec_001A6810 m100;
    Vec_001A6810 m110;
    int m_pad120[4];
    Vec_001A6810 m130;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m_pad150[4];
    Vec_001A6810 m160;
    Vec_001A6810 m170;
    Vec_001A6810 m180;
    Vec_001A6810 m190;
    Vec_001A6810 m1A0;
    Vec_001A6810 m1B0;
    Vec_001A6810 m1C0;
    int m1D0;
    int m1D4;
    int m1D8;
    int m_pad1DC[6];
    int m1F4;
    int m1F8;
    void Reset();
};

void C_001A6810::Reset()
{
    m160.Set(0.0f, 0.0f, 0.0f);
    m170.Set(0.0f, 0.0f, 0.0f);
    m180.Set(0.0f, 0.0f, 0.0f);
    m190.Set(0.0f, 0.0f, 0.0f);
    m1A0.Set(0.0f, 0.0f, 0.0f);
    m1B0.Set(0.0f, 0.0f, 0.0f);
    m1C0.Set(0.0f, 0.0f, 0.0f);
    m130.Set(0.0f, 0.0f, 0.0f);
    m140 = 0;
    m144 = 0;
    m24 = 0;
    m148 = 0;
    m14C = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m1D0 = 0;
    m1D4 = 0;
    m1D8 = 0;
    m1F4 = 0;
    m1F8 = 0;
    m1C = 0;
    m20 = 0;
    m50.Set(0.0f, 0.0f, 0.0f);
    m60.Set(0.0f, 0.0f, 0.0f);
    m70.Set(0.0f, 0.0f, 0.0f);
    m90.Set(0.0f, 0.0f, 0.0f);
    mA0.Set(0.0f, 0.0f, 0.0f);
    mB0.Set(0.0f, 0.0f, 0.0f);
    mC0.Set(0.0f, 0.0f, 0.0f);
    mD0.Set(0.0f, 0.0f, 0.0f);
    mE0.Set(0.0f, 0.0f, 0.0f);
    mF0.Set(0.0f, 0.0f, 0.0f);
    m100.Set(0.0f, 0.0f, 0.0f);
    m110.Set(0.0f, 0.0f, 0.0f);
}
