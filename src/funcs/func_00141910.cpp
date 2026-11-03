struct Vec_00141910 {
    float x, y, z, w;
    Vec_00141910() {}
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Color_00141910 {
    unsigned char r, g, b, a;
    Color_00141910() {}
};

class C_00141910 {
public:
    int m0;
    unsigned int m4;
    int m8;
    float mC[3];
    int m18[3];
    int m24;
    float m28;
    float m2C;
    float m30;
    char pad34[0x4C];
    Vec_00141910 m80[3];
    Vec_00141910 mB0[3];
    int mE0;
    char padE4[0xC];
    Vec_00141910 mF0[3];
    int m120;
    float m124;
    Color_00141910 m128[3];
    unsigned int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    C_00141910();
};

C_00141910::C_00141910()
{
    m8 = 1;
    m4 = 0xDEDFC057;
    mE0 = 0;
    for (int i = 0; i < 3; i++) {
        mC[i] = 1.0f;
        m18[i] = 0;
        m80[i].Set(0.0f, 0.0f, 0.0f, 0.0f);
        mB0[i].Set(20.0f, 20.0f, 20.0f, 0.0f);
        mF0[i].Set(0.0f, 0.0f, 0.0f, 0.0f);
        m128[i].r = 0x80;
        m128[i].g = 0x80;
        m128[i].b = 0x80;
        m128[i].a = 0x80;
    }
    m24 = 2;
    m28 = 300.0f;
    m2C = 4.0f;
    m30 = 50.0f;
    m124 = 50.0f;
    m134 = 0xA86285A1;
    m13C = 1;
    m144 = 0x190;
    m148 = 0x191;
    m120 = 0;
    m140 = 0;
    m138 = 0;
    m14C = 0;
    m150 = 0;
    m154 = 0;
}
