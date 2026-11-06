/* sym: __13Base_0018E2C0 = 0x00184DC0 */
/* sym: _vt$13Comp_0018E2C0 = 0x00361FE0 */

extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

struct Vec_0018E2C0 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Base_0018E2C0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_0018E2C0();
    virtual ~Base_0018E2C0();
};

struct Comp_0018E2C0 : Base_0018E2C0 {
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    int m50;
    short m54;
    char pad56[0x70 - 0x56];
    Vec_0018E2C0 m70;
    float m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    float mA8;
    float mAC;
    int mB0;
    int mB4;
    char padB8[0xD0 - 0xB8];
    float mD0;
    char padD4[0x100 - 0xD4];
    Vec_0018E2C0 m100;
    char pad110[0x16C - 0x110];
    int m16C;
    Comp_0018E2C0();
    virtual void Update();
    virtual ~Comp_0018E2C0();
};

Comp_0018E2C0::Comp_0018E2C0()
{
    mB4 = 0;
    m100.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m_type = 0xFFB39248;
    m20 = -386.4f;
    m1C = 0.003f;
    m24 = 0.4f;
    m28 = 0.5f;
    m2C = 10.0f;
    m48 = 100.0f;
    m4C = 0.160000011f;
    m30 = 48.0f;
    m34 = 12.0f;
    float a = 0.436332345f;
    m40 = 1.0f;
    m44 = 1.0f;
    m16C = 0;
    m38 = func_00340F60(a);
    m3C = func_00341068(a);
    m80 = 1.0f / 12.0f;
    m70.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mA0 = 1000;
    mA4 = 100;
    mA8 = 20.0f;
    mAC = 300.0f;
    mD0 = -1.0f;
    m54 = 0;
    m90 = 0;
    m8C = 0;
    m88 = 0;
    m84 = 0;
    m94 = 0;
    m9C = 0;
    m98 = 0;
    mB0 = 0;
    m50 = 0;
}
