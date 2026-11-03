struct Comp_00205870 {
    char pad[0x1C];
    int m_active;
};

struct Board_00205870 {
    char pad[0x244];
    int m_m244;
};

struct Anim_00205870 {
    char pad[0x1C];
    void* m_anim;
};

extern "C" Comp_00205870* func_00185578(void* self, unsigned int name);
extern "C" void func_00273250(Comp_00205870* c, int a);
extern "C" void func_00291A68(void* c);
extern "C" void func_00291D68(void* c);
extern "C" void func_001AB720(void* p);
extern "C" void func_001AB788(void* p);
extern "C" void func_001AEE68(void* p);
extern "C" void func_001AB758(void* p);
extern "C" void func_001ADCF0(void* p);
extern "C" void func_001B0F18(void* p);
extern "C" void func_00239158(void* p, int a, float t);
extern "C" void func_00239178(void* p, int a, float t);
extern "C" void func_001BABD8(void* p);
extern "C" void func_001B6BC0(void* p, void* m);
extern "C" void func_001B6BD0(void* p, void* m);

struct Skater_00205870 {
    char pad[0x50];
    char m_m50[0x30];
    char m_m80[0x238 - 0x80];
    int m_m238;
    char pad23C[0x2B4 - 0x23C];
    Board_00205870* m_board;
    void* m_m2B8;
    void* m_m2BC;
    void* m_m2C0;
    char pad2C4[0x2D8 - 0x2C4];
    Anim_00205870* m_m2D8;
    void Reset();
};

void Skater_00205870::Reset()
{
    Comp_00205870* c = func_00185578(this, 0xD9151D4D);
    if (c->m_active) {
        func_00273250(c, 0);
    }
    func_00291A68(func_00185578(this, 0x488AF07A));
    func_001AB720(m_m2BC);
    func_001AB788(m_m2BC);
    func_001AEE68(m_m2BC);
    func_001AB758(m_m2BC);
    func_001ADCF0(m_m2BC);
    func_001B0F18(m_m2BC);
    func_00291D68(func_00185578(this, 0x43686585));
    m_board->m_m244 = 0;
    func_00239158(m_m2D8->m_anim, 0, 0.0f);
    func_00239178(m_m2D8->m_anim, 0, 0.0f);
    if (m_m2C0) {
        func_001BABD8(m_m2C0);
    }
    func_001B6BC0(m_m2B8, m_m50);
    func_001B6BD0(m_m2B8, m_m80);
    m_m238 = 1;
    func_00185578(this, 0x21FC3301)->m_active = -1;
}
