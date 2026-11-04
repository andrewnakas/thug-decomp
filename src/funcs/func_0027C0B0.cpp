typedef int qword_0027C0B0 __attribute__((mode(TI)));

extern void* D_00388A70;
extern void* D_00392068;

extern "C" int func_0010FC30();
extern "C" int func_002A19A8(void* net);
extern "C" void func_00183CB8(void* obj, void* holder);
extern "C" void func_0010A8D8(void* heap, void* p);

struct Vec_0027C0B0 {
    union {
        qword_0027C0B0 q;
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

struct Flag_0027C0B0 {
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

struct Phys_0027C0B0 {
    char m_pad[0x24];
    Flag_0027C0B0 m24[23];
    char m_pad2[0x150 - 0x138];
    int m150;
};

struct Model_0027C0B0 {
    char m_pad[0x50];
    Vec_0027C0B0 m50;
    Vec_0027C0B0 m60;
    char m_pad2[0xB0 - 0x70];
    Vec_0027C0B0 mB0;
    char m_pad3[0x164 - 0xC0];
    bool m164;
};

struct Thing_0027C0B0 {
    void* m0;
};

struct Holder_0027C0B0 {
    char m_pad[0x1C];
    Thing_0027C0B0* m1C;
    int m20;
    void Clear()
    {
        Thing_0027C0B0* t = m1C;
        if (t) {
            if (t->m0) {
                func_00183CB8(t->m0, t);
                t->m0 = 0;
            }
            func_0010A8D8(D_00388A70, t);
            m1C = 0;
            m20 = func_0010FC30();
        }
    }
};

struct Ctrl_0027C0B0 {
    char m_pad[0x28];
    int m28;
};

struct Sub_0027C0B0 {
    char m_pad[0x89];
    char m89;
    void Reset() { m89 = 0; }
};

struct Skater_0027C0B0 {
    char m_pad[0xC];
    Model_0027C0B0* mC;
    char m_pad1[0x98 - 0x10];
    int m98;
    int m9C;
    Vec_0027C0B0 mA0;
    char m_pad2[0x190 - 0xB0];
    Sub_0027C0B0 m190;
    char m_pad3[0x29C - 0x21A];
    int m29C;
    char m_pad4[0x2E0 - 0x2A0];
    Vec_0027C0B0 m2E0;
    char m_pad5[0x354 - 0x2F0];
    int m354;
    char m_pad6[0x370 - 0x358];
    int m370;
    int m374;
    char m_pad7[0x384 - 0x378];
    int m384;
    char m_pad8[0x3B4 - 0x388];
    int m3B4;
    char m_pad9[0x3D4 - 0x3B8];
    int m3D4;
    int m3D8;
    char m_pad10[0x3F0 - 0x3DC];
    int m3F0;
    char m_pad11[0x420 - 0x3F4];
    int m420;
    char m_pad12[0x430 - 0x424];
    float m430;
    char m_pad13[0x580 - 0x434];
    int m580;
    int m584;
    int m588;
    char m_pad14[0x59C - 0x58C];
    Ctrl_0027C0B0* m59C;
    char m_pad15[0x5B0 - 0x5A0];
    Phys_0027C0B0* m5B0;
    Holder_0027C0B0* m5B4;
    void ResetPhysics();
};

extern "C" void func_0027C720(Skater_0027C0B0* self, int state);

void Skater_0027C0B0::ResetPhysics()
{
    if (!func_002A19A8(D_00392068)) {
        mC->m60 = mC->m50;
        mA0 = mC->m50;
    }
    m2E0.Set(0.0f, 0.0f, 0.0f);
    m98 = func_0010FC30();
    mC->mB0.Set(0.0f, 0.0f, 0.0f);
    func_0027C720(this, 0);
    m9C = 0;
    int i = 23;
    while (i--) {
        m5B0->m24[i].Set(1);
        if (i == 7)
            m59C->m28 = 1;
        m5B0->m24[i].Set(0);
        if (i == 7)
            m59C->m28 = 0;
    }
    m5B0->m24[1].Set(!mC->m164);
    m5B4->Clear();
    m190.Reset();
    m374 = 1;
    m354 = 0;
    m3F0 = 0;
    m420 = 0;
    m3D4 = 0;
    m3D8 = 0;
    m370 = 0;
    m5B0->m150 = 0;
    m430 = 1.0f;
    m29C = 0;
    m3B4 = 0;
    m580 = 0;
    m584 = 0;
    m588 = 0;
    m384 = 0;
}
