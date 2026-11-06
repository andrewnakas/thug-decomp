/* fuzzy: 92.7 */
extern "C" void func_00184920(void* obj, unsigned int name, float a, int b);

struct Btn_0019B920 {
    char pad0[0x4];
    int m4;
};

struct Input_0019B920 {
    char pad0[0x50];
    int m50;
    char pad54[0x74 - 0x54];
    int m74;
    char pad78[0x104 - 0x78];
    int m104;
    char pad108[0x190 - 0x108];
    Btn_0019B920 m190;
    char pad198[0x1B8 - 0x198];
    int m1B8;
    char pad1BC[0x1DC - 0x1BC];
    int m1DC;
    char pad1E0[0x25C - 0x1E0];
    float m25C;
};

struct Pad_0019B920 {
    char pad0[0x24];
    Input_0019B920 m_input;
};

struct Obj_0019B920 {
    char pad0[0xC];
    void* mC;
    char pad10[0x60 - 0x10];
    int m60;
    int m64;
    char pad68[0x90 - 0x68];
    float m90;
    float m94;
    float m98;
    char pad9C[0xB0 - 0x9C];
    float mB0;
    float mB4;
    float mB8;
    char padBC[0x120 - 0xBC];
    int m120;
    char pad124[0x310 - 0x124];
    int m310;
    int m314;
    char pad318[0x34C - 0x318];
    float m34C;
    int m350;
    int m354;
    int m358;
    int m35C;
    char pad360[0x1364 - 0x360];
    int m1364;
    char pad1368[0x1378 - 0x1368];
    Pad_0019B920* m1378;
    float Speed() const { return mB0 * m90 + mB4 * m94 + mB8 * m98; }
    void ReadInput();
};

static inline bool Held_0019B920(Obj_0019B920* o, Input_0019B920* in, Btn_0019B920* b)
{
    bool r = false;
    if (b->m4 || (o->m310 && in->m1B8)) {
        r = true;
    }
    return r;
}

void Obj_0019B920::ReadInput()
{
    int on = 1;
    Input_0019B920* in = &m1378->m_input;
    m34C = in->m25C * __builtin_fabsf(in->m25C);
    if (m34C == 0.0f) {
        if (m1378->m_input.m50 && !m1378->m_input.m74) {
            m34C = -1.0f;
        } else if (in->m74 && !in->m50) {
            m34C = 1.0f;
        }
    }
    m350 = in->m1DC;
    m358 = in->m104 && !m314;
    Btn_0019B920* b = &in->m190;
    if (Held_0019B920(this, in, b)) {
        int fwd = on;
        if (b->m4) {
            fwd = 0;
        }
        if (m35C || (Speed() < 300.0f && m120)) {
            if (m60 || m120) {
                m354 = 0;
                m35C = on;
                goto done;
            }
        }
        m35C = 0;
        m354 = 1;
    done:
        if (fwd) {
            if (Speed() < 0.0f) {
                m35C = 0;
                m354 = 1;
            }
            if (__builtin_fabsf(Speed()) < 30.0f) {
                func_00184920(mC, 0xCBAA3476, 0.0f, 0);
            }
        }
    } else {
        m35C = 0;
        m354 = 0;
    }
    if (m1364) {
        m35C = 0;
        m354 = 1;
    }
    if (!m60 && (m350 || m35C)) {
        m64 = 0;
        m60 = 1;
    }
}
