typedef int qword_0027C720 __attribute__((mode(TI)));

extern "C" int func_0010FC30();
extern "C" void func_001B0EB8(void* p, int a);
extern "C" void func_0026FDC8(void* rec);

struct Vec_0027C720 {
    union {
        qword_0027C720 q;
        struct {
            float x, y, z, w;
        } f;
    };
    void Set(float ax, float ay, float az)
    {
        f.x = ax;
        f.y = ay;
        f.z = az;
        f.w = 1.0f;
    }
};

struct Flag_0027C720 {
    int m0;
    int m4;
    int m8;
    void Set(int v)
    {
        if (m4 != v) {
            m4 = v;
            m8 = func_0010FC30();
        }
    }
};

struct Phys_0027C720 {
    char m_pad[0x1C];
    int m1C;
    char m_pad2[0x78 - 0x20];
    Flag_0027C720 m78;
    char m_pad3[0x114 - 0x84];
    Flag_0027C720 m114;
    char m_pad4[0x12C - 0x120];
    Flag_0027C720 m12C;
};

struct Model_0027C720 {
    char m_pad[0x50];
    Vec_0027C720 m50;
    Vec_0027C720 m60;
};

struct Ctrl_0027C720 {
    char m_pad[0x1C];
    int m1C;
    char m_pad2[8];
    int m28;
};

struct Pad_0027C720 {
    char m_pad[0x13F0];
    int m13F0;
};

struct Skater_0027C720 {
    char m_pad[0xC];
    Model_0027C720* mC;
    char m_pad2[0x98 - 0x10];
    int m98;
    int m9C;
    char m_pad3[0x2E0 - 0xA0];
    Vec_0027C720 m2E0;
    char m_pad4[0x36C - 0x2F0];
    int m36C;
    char m_pad5[0x3F8 - 0x370];
    int m3F8;
    int m3FC;
    char m_pad6[0x594 - 0x400];
    char* m594;
    char m_pad7[0x59C - 0x598];
    Ctrl_0027C720* m59C;
    Pad_0027C720* m5A0;
    char m_pad8[0x5B0 - 0x5A4];
    Phys_0027C720* m5B0;
    void SetState(int state);
};

void Skater_0027C720::SetState(int state)
{
    if (m5B0->m1C != state) {
        m98 = func_0010FC30();
        m9C = m5B0->m1C;
    }
    if (m5B0->m1C == 3 && state != 3) {
        if (m2E0.f.x != 0.0f || m2E0.f.y != 0.0f || m2E0.f.z != 0.0f) {
            mC->m50 = m2E0;
            mC->m60 = mC->m50;
        }
    }
    if (state != 3)
        m2E0.Set(0.0f, 0.0f, 0.0f);
    if (state)
        func_001B0EB8(m5A0, 1);
    if (m5B0->m1C == 4 && state != 4) {
        m5B0->m78.Set(0);
        m59C->m28 = 0;
    }
    int cur = m5B0->m1C;
    if (cur == 1) {
        if (state != 1) {
            m3FC = func_0010FC30();
            m5B0->m114.Set(0);
            m5B0->m12C.Set(0);
        }
    } else if (state == 1) {
        if (cur != 2)
            m3F8 = func_0010FC30();
        m5A0->m13F0 = 0;
        func_0026FDC8(m594 + 0xB8);
        func_0026FDC8(m594 + 0x124);
        m36C = 0;
    }
    m5B0->m1C = state;
    m59C->m1C = state;
}
