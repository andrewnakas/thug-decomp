/* cflags: -fno-schedule-insns */
typedef int qword __attribute__((mode(TI)));

struct Timer_0027A428 {
    int m0;
    int m_active;
    int m_time;
};

struct Info_0027A428 {
    char pad0[0x1C];
    int m_mode;
    char pad20[0x40 - 0x20];
    int m40;
    char pad44[0xAC - 0x44];
    int mAC;
    char padB0[0xD8 - 0xB0];
    Timer_0027A428 m_t0;
    Timer_0027A428 m_t1;
};

struct Body_0027A428 {
    char pad0[0x50];
    qword m_pos;
};

extern "C" float func_0010FAB8();
extern "C" int func_0010FC30();
extern "C" void func_0028E170(void* self, Info_0027A428* info);
extern "C" void func_0027CA10(void* self);
extern "C" void func_0028EB88(void* self);
extern "C" void func_0027CD28(void* self);
extern "C" void func_00285308(void* self);
extern "C" void func_00285528(void* self);
extern "C" void func_00288868(void* self);
extern "C" void func_0028C0F0(void* self);
extern "C" void func_0028C3F0(void* self);
extern "C" void func_00289928(void* self);
extern "C" void func_002828D8(void* self);
extern "C" void func_00289B00(void* self, int a);
extern "C" void func_0028EC88(void* self);
extern "C" void func_00184920(Body_0027A428* body, unsigned int crc, int a, float f);
extern int D_0038EE60;


struct Self_0027A428 {
    char pad0[0xC];
    Body_0027A428* m_body;
    char pad10[0x94 - 0x10];
    float m_time;
    char pad98[0x2CC - 0x98];
    bool m2CC;
    int m2D0;
    bool m2D4;
    char pad2D8[0x3A0 - 0x2D8];
    qword m_pos;
    char pad3B0[0x58C - 0x3B0];
    bool m58C;
    char pad590[0x5B0 - 0x590];
    Info_0027A428* m_info;

    void Update();
};

void Self_0027A428::Update()
{
    m_time = func_0010FAB8();
    m2CC = false;
    m2D4 = m_info->m_mode == 3;
    m2D0 = m_info->mAC;
    func_0028E170(this, m_info);
    func_0027CA10(this);
    Timer_0027A428* t = &m_info->m_t0;
    if (t->m_active) {
        t->m_active = 0;
        t->m_time = func_0010FC30();
    }
    t = &m_info->m_t1;
    if (t->m_active) {
        t->m_active = 0;
        t->m_time = func_0010FC30();
    }
    func_0028EB88(this);
    switch (m_info->m_mode) {
    case 0:
        m_pos = m_body->m_pos;
        func_0027CD28(this);
        func_00285308(this);
        break;
    case 1:
        func_00285528(this);
        if (m_info->m_mode == 0)
            m2CC = true;
        break;
    case 2:
        func_00288868(this);
        break;
    case 3:
        func_0028C0F0(this);
        break;
    case 4:
        func_0028C3F0(this);
        break;
    case 5:
        func_00289928(this);
        break;
    }
    func_002828D8(this);
    func_00289B00(this, 0);
    func_0028EC88(this);
    bool want = false;
    if (m_info->m_mode == 1 && m_info->m40 && !m_info->mAC)
        want = true;
    if (m58C != want) {
        m58C = !m58C;
        func_00184920(m_body, m58C ? 0xF225FE69 : 0x5E27200A, 0, 0.0f);
    }
    D_0038EE60 = 0;
}
