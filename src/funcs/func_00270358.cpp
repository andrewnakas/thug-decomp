/* sym: __12Mem_00270358 = 0x001DC540 */
/* sym: _$_12Mem_00270358 = 0x001DC578 */
extern "C" float fabsf(float);

struct Mem_00270358 {
    float m_v[5];
    int m_type;
    Mem_00270358();
    ~Mem_00270358();
};

struct Snd_00270358 {
    int m0;
    int m4;
    float m8;
    float mC;
    int m10[4];
};

struct Body_00270358 {
    char pad0[0x50];
    float m50[4];
};

extern Snd_00270358 D_003765B8;
extern void* D_0038E0A0;

extern "C" float func_0010FAB8();
extern "C" int func_001DBFE8(Snd_00270358* s, int a, int b, float c);
extern "C" float func_001DC330(Snd_00270358* s, int a, float b);
extern "C" void func_001DC5A8(Mem_00270358* m, float s);
extern "C" bool func_001DC658(Mem_00270358* m);
extern "C" void func_001DC6D0(Mem_00270358* m);
extern "C" int func_001DD290(void* mgr, int id, Mem_00270358* m, int a, int b, int c, float f);
extern "C" void func_001DD448(void* mgr, int h);
extern "C" float func_001DD758(void* mgr, int id);
extern "C" void func_001DD7C8(void* mgr, int h, Mem_00270358* m, float f);
extern "C" void func_001DDB00(void* mgr, Mem_00270358* m, float* pos, int a, float b, int c, int d);

struct Base_00270358 {
    int m0;
    int m4;
    int m8;
    Body_00270358* mC;
    int m10;
    int m14;
    virtual void V0_00270358();
    virtual void V1_00270358();
    virtual void V2_00270358();
    virtual void V3_00270358();
    virtual void V4_00270358();
    virtual void V5_00270358();
    virtual void Suspend_00270358(int suspend);
};

struct Comp_00270358 : Base_00270358 {
    int m1C;
    int m20;
    float m24;
    float m28;
    Mem_00270358 m2C;
    float m44;
    float m48;
    int m4C;
    int m50;
    int m54;
    Snd_00270358 m58;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    float m8C;
    float m90;
    int m94;
    void Update();
};

void Comp_00270358::Update()
{
    if (!m94) {
        Suspend_00270358(1);
        return;
    }
    Mem_00270358 m;
    switch (m54) {
    case 4:
        if (m84) {
            m78 = 0;
        } else {
            int mode = m88 ? 7 : 1;
            if (m7C) {
                m78 = func_001DBFE8(&m58, m50, mode, 0.0f);
                m7C = 0;
            }
        }
        break;
    case 0:
        if (m7C) {
            m78 = func_001DBFE8(&m58, m50, 0, 0.0f);
            m7C = 0;
        }
        break;
    case 1:
        if (m7C) {
            m78 = 1;
            m58 = D_003765B8;
            m7C = 0;
        }
        break;
    }
    if (m1C && (!m78 || m20 != m58.m4)) {
        func_001DD448(D_0038E0A0, m1C);
        m1C = 0;
    }
    if (!m78)
        return;
    void* mgr = D_0038E0A0;
    func_001DDB00(mgr, &m, mC->m50, 0, func_001DD758(mgr, m58.m4), 0, 0);
    float f;
    if (m54 == 1 && m1C) {
        if (m24 > m44)
            m24 -= m48 * func_0010FAB8();
        else
            func_001DC6D0(&m);
        f = m24;
    } else {
        if (m8C > 0.0f) {
            float pct = m90 * 100.0f;
            func_001DC5A8(&m, func_001DC330(&m58, 0, m8C * pct));
            f = m8C * (m58.m8 - m58.mC) + m58.mC;
        } else {
            func_001DC6D0(&m);
            f = 0.0f;
        }
        m24 = f;
    }
    if (func_001DC658(&m)) {
        if (m1C) {
            func_001DD448(D_0038E0A0, m1C);
            m1C = 0;
        }
        return;
    }
    if (!m1C) {
        m2C = m;
        m28 = f;
        m1C = func_001DD290(mgr, m58.m4, &m, 0, 0, m58.m0, f);
        if (!m1C)
            return;
        m20 = m58.m4;
    } else if (m80 || fabsf(m.m_v[0] - m2C.m_v[0]) > 0.5f || fabsf(f - m28) > 0.5f) {
        m2C = m;
        m28 = f;
        m80 = 0;
        func_001DD7C8(mgr, m1C, &m, f);
    }
}
