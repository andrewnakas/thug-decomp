/* sym: __13Base_00192DD0 = 0x00184DC0 */
/* sym: _vt$12Der_00192DD0 = 0x00362140 */
/* sym: __12Mat_00192DD0 = 0x00101F58 */
/* sym: __12Sub_00192DD0 = 0x001DA890 */
struct Quat_00192DD0 {
    float x, y, z, w;
    Quat_00192DD0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Vec_00192DD0 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

class Mat_00192DD0 {
public:
    char m0[0x30];
    Mat_00192DD0();
};

struct Pair_00192DD0 {
    Mat_00192DD0 a;
    Mat_00192DD0 b;
    char pad60[0x90 - 0x60];
};

class Sub_00192DD0 {
public:
    char m0[0x1340 - 0x360];
    Sub_00192DD0();
};

class Base_00192DD0 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_00192DD0();
    virtual void F();
};

class Der_00192DD0 : public Base_00192DD0 {
public:
    char pad1C[0x40 - 0x1C];
    Quat_00192DD0 m40;
    char pad50[0x60 - 0x50];
    int m60;
    int m64;
    int m68;
    char pad6C[0x134 - 0x6C];
    int m134;
    char pad138[0x1E0 - 0x138];
    Pair_00192DD0 m1E0[2];
    char pad300[0x318 - 0x300];
    void* m318;
    char pad31C[0x360 - 0x31C];
    Sub_00192DD0 m360;
    Vec_00192DD0 m1340;
    int m1350;
    int m1354;
    unsigned int m1358;
    char pad135C[0x1378 - 0x135C];
    int m1378;
    int m137C;
    int m1380;
    int m1384;
    Der_00192DD0();
    virtual void F();
};

Der_00192DD0::Der_00192DD0()
{
    m1378 = 0;
    m4 = 0xE47F1B79;
    m1380 = 0;
    m1384 = 0;
    m1354 = 0;
    m1340.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m1358 = 0x1CA1FF20;
    m60 = 1;
    m318 = 0;
    m68 = 0;
    m134 = 0;
    m64 = 0;
}
