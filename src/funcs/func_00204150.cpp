extern char D_00366D88[];
extern char D_00366DA7[];
extern char D_00366DE0[];
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_00107F18(void* p);

struct Comp_00204150 {
    char pad0[0x80];
    int m80;
};

struct Inner_00204150 {
    char pad0[0x20];
    void* m20;
};

struct Holder_00204150 {
    char pad0[0x51C];
    Inner_00204150* m51C;
};

struct Skater_00204150;
extern "C" Comp_00204150* func_00185578(Skater_00204150* s, unsigned int crc);

struct Skater_00204150 {
    char pad0[0x104];
    int m104;
    char pad108[0x150 - 0x108];
    int m_paused;
    char pad154[0x2C8 - 0x154];
    Holder_00204150* m2C8;
    char pad2CC[0x31C - 0x2CC];
    int m31C;

    void UnPause();
};

void Skater_00204150::UnPause()
{
    if (m_paused && m31C) {
        func_00103F28(D_00366D88, D_00366DA7, 0x3A3, D_00366DE0);
        m_paused = 0;
        m104 &= ~1;
        if (m2C8)
            func_00107F18(m2C8->m51C->m20);
        Comp_00204150* c = func_00185578(this, 0xB5F1E9D2);
        if (c)
            c->m80 = 1;
    }
}
