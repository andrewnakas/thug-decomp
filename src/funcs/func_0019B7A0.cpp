extern float D_00387838;

struct Vec_0019B7A0 {
    float x, y, z, w;
    float LengthSq() const { return x * x + y * y + z * z; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Wheel_0019B7A0 {
    char pad0[0xB4];
    int mB4;
    char padB8[0x220 - 0xB8];
};

struct Obj_0019B7A0 {
    char pad0[0x30];
    Vec_0019B7A0 m30;
    char pad40[0x50 - 0x40];
    Vec_0019B7A0 m50;
    int m60;
    int m64;
    unsigned int m68;
    char pad6C[0xB0 - 0x6C];
    Vec_0019B7A0 mB0;
    Vec_0019B7A0 mC0;
    char padD0[0x120 - 0xD0];
    unsigned int m120;
    char pad124[0x134 - 0x124];
    float m134;
    char pad138[0x140 - 0x138];
    Vec_0019B7A0 m140;
    Vec_0019B7A0 m150;
    char pad160[0x1C4 - 0x160];
    unsigned int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_0019B7A0* m_wheels;
    char pad31C[0x350 - 0x31C];
    int m350;
    char pad354[0x35C - 0x354];
    int m35C;
    void Update();
};

void Obj_0019B7A0::Update()
{
    int count = m64;
    m64 = 0;
    if (m350)
        return;
    if (m35C && m120)
        return;
    if (m120 + m68 < 3)
        return;
    if (m120 && m120 != m_numWheels)
        return;
    if (mB0.LengthSq() > 1.0f)
        return;
    if (mC0.LengthSq() > D_00387838)
        return;
    bool pos = m134 > 0.0f;
    if (pos)
        return;
    m64 = count + 1;
    if (count + 1 < 3)
        return;
    m30.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m50.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m140.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m150.Set(0.0f, 0.0f, 0.0f, 1.0f);
    int i = m_numWheels;
    while (i-- != 0)
        m_wheels[i].mB4 = 0;
    m60 = 0;
}
