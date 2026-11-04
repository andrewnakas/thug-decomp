typedef int qword __attribute__((mode(TI)));

struct C_001BE448;
extern "C" void func_001C5FB8(C_001BE448* self);
extern "C" void func_001C5BB0(C_001BE448* self);
extern "C" float func_0010FAB8();
extern "C" void func_001C6540(C_001BE448* self);
extern "C" void func_001BF2F0(C_001BE448* self);
extern "C" void func_001C2050(C_001BE448* self);
extern "C" void func_001C92D0(C_001BE448* self);
extern "C" void func_001CC608(C_001BE448* self);
extern "C" void func_001C42C8(C_001BE448* self);
extern "C" void* func_001E5548(unsigned int name, int flag);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001C3F28(C_001BE448* self);
extern "C" void func_001C54A8(C_001BE448* self);
extern "C" void func_001C5920(C_001BE448* self);
extern "C" void func_001C33E8(C_001BE448* self);
extern "C" void func_001C3590(C_001BE448* self);
extern "C" void func_001C5CF0(C_001BE448* self);
extern "C" void func_001C36F8(C_001BE448* self);
extern "C" void func_001C65F0(C_001BE448* self, unsigned int prev);
extern "C" void func_001848F0(void* obj, unsigned int name, int flags);
extern "C" void func_001C6888(C_001BE448* self);
extern "C" void func_001C66D0(C_001BE448* self);

struct State_001BE448 {
    int m_pad[74];
    int m128;
};

struct Info_001BE448 {
    int m_pad[11];
    int m2C;
};

struct C_001BE448 {
    int m_pad[3];
    void* mC;
    int m10[3];
    unsigned int m1C;
    int m20[4];
    union {
        qword m30;
        struct { float m30x, m34, m38, m3C; };
    };
    int m40[16];
    qword m80;
    unsigned int m90;
    unsigned int m94;
    float m98;
    int m9C[8];
    int mBC;
    int mC0[552];
    float m960;
    int m964;
    int m968[48];
    State_001BE448* mA28;
    int mA2C[3];
    Info_001BE448* mA38;
    void Update();
};

void C_001BE448::Update()
{
    unsigned int prev = m90;
    if (mBC && !mA28->m128) mBC = 0;
    m94 = m90;
    m90 = 0;
    func_001C5FB8(this);
    func_001C5BB0(this);
    m80 = m30;
    m98 = func_0010FAB8();
    m964 = 0;
    m34 -= m960;
    func_001C6540(this);
    switch (m1C) {
    case 0:
        func_001BF2F0(this);
        break;
    case 1:
        func_001C2050(this);
        break;
    case 2:
        func_001C92D0(this);
        break;
    case 3:
        func_001CC608(this);
        break;
    case 4:
        func_001C42C8(this);
        break;
    }
    if (mA38->m2C) return;
    if (!m964) {
        float g;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x9B3388FA, &g, 1);
        m960 += -m960 * (g * m98);
    }
    m34 += m960;
    if (m1C == 0) {
        func_001C3F28(this);
        if (mA38->m2C) return;
    }
    func_001C54A8(this);
    func_001C5920(this);
    if (m1C < 2) func_001C33E8(this);
    func_001C3590(this);
    func_001C5CF0(this);
    func_001C36F8(this);
    func_001C65F0(this, prev);
    func_001848F0(mC, m90, 0);
    func_001C6888(this);
    func_001C66D0(this);
}
