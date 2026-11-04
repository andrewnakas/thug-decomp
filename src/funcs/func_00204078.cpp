extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00239158(void* p, int a, float f);
extern "C" void func_00239178(void* p, int a, float f);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_00107E70(void* p);
extern "C" void func_001DC9E8(void* p);
extern void* D_0038E0A0;
extern char D_00366D88[];
extern char D_00366DA7[];
extern char D_00366DC0[];

struct Anim_00204078 {
    char pad[0x1C];
    void* m1C;
};

struct Model_00204078 {
    char pad[0x20];
    void* m20;
};

struct Board_00204078 {
    char pad[0x51C];
    Model_00204078* m51C;
};

struct Skater_00204078 {
    char pad[0x104];
    unsigned int m104;
    char pad2[0x150 - 0x108];
    int m150;
    char pad3[0x2C8 - 0x154];
    Board_00204078* m2C8;
    char pad4[0x2D8 - 0x2CC];
    Anim_00204078* m2D8;
    char pad5[0x31C - 0x2DC];
    int m31C;
    void Bail();
};

void Skater_00204078::Bail()
{
    if (m150) return;
    if (!m31C) return;
    func_00103F28(D_00366D88, D_00366DA7, 0x383, D_00366DC0);
    m150 = 1;
    m104 |= 1;
    func_00239158(m2D8->m1C, 0, 0.0f);
    func_00239178(m2D8->m1C, 0, 0.0f);
    func_001F0210(0x1277E3FD, 0, 0, 0, 0);
    if (m2C8) func_00107E70(m2C8->m51C->m20);
    func_001DC9E8(D_0038E0A0);
}
