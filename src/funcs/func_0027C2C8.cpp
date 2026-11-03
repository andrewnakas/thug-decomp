typedef int qword_0027C2C8 __attribute__((mode(TI)));

extern void* D_00388A70;

extern "C" int func_0010FC30();
extern "C" void func_00183CB8(void* obj, void* holder);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0020A6C0(void* p, int id);

struct Vec_0027C2C8 {
    union {
        qword_0027C2C8 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Mat_0027C2C8 {
    Vec_0027C2C8 r[4];
};

struct Flag_0027C2C8 {
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

struct Phys_0027C2C8 {
    char m_pad[0xFC];
    Flag_0027C2C8 mFC;
    char m_pad2[0x114 - 0x108];
    Flag_0027C2C8 m114;
    char m_pad3[0x150 - 0x120];
    int m150;
};

struct Model_0027C2C8 {
    char m_pad[0x50];
    Vec_0027C2C8 m50;
    Vec_0027C2C8 m60;
    Mat_0027C2C8 m70;
    void GetMatrix(Mat_0027C2C8& out)
    {
        out.r[0] = m70.r[0];
        out.r[1] = m70.r[1];
        out.r[2] = m70.r[2];
        out.r[3] = m70.r[3];
    }
};

struct Thing_0027C2C8 {
    void* m0;
};

struct Holder_0027C2C8 {
    char m_pad[0x1C];
    Thing_0027C2C8* m1C;
    int m20;
    void Clear()
    {
        Thing_0027C2C8* t = m1C;
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

struct Opts_0027C2C8 {
    char m_pad[0xC0];
    int mC0;
};

struct Rail_0027C2C8 {
    char m_pad[0x10];
    int m10;
    int m14;
    int m18;
};

struct Skater_0027C2C8 {
    char m_pad[0xC];
    Model_0027C2C8* mC;
    char m_pad1[0x20 - 0x10];
    Mat_0027C2C8 m20;
    Vec_0027C2C8 m60;
    Vec_0027C2C8 m70;
    Vec_0027C2C8 m80;
    char m_pad2[0x98 - 0x90];
    int m98;
    int m9C;
    Vec_0027C2C8 mA0;
    char m_pad3[0x219 - 0xB0];
    char m219;
    char m_pad4[0x354 - 0x21A];
    int m354;
    char m_pad5[0x370 - 0x358];
    int m370;
    int m374;
    char m_pad6[0x3B4 - 0x378];
    int m3B4;
    char m_pad7[0x3D4 - 0x3B8];
    int m3D4;
    char m_pad8[0x3F0 - 0x3D8];
    int m3F0;
    char m_pad9[0x420 - 0x3F4];
    int m420;
    char m_pad10[0x430 - 0x424];
    float m430;
    char m_pad11[0x580 - 0x434];
    int m580;
    int m584;
    int m588;
    char m_pad12[0x5B0 - 0x58C];
    Phys_0027C2C8* m5B0;
    Holder_0027C2C8* m5B4;
    char m_pad13[0x5BC - 0x5B8];
    Opts_0027C2C8* m5BC;
    void Respawn(bool air, Rail_0027C2C8* rail, int node);
};

extern "C" void func_0027C640(Skater_0027C2C8* self);
extern "C" void func_0027C720(Skater_0027C2C8* self, int state);
extern "C" void func_0028AAF8(Skater_0027C2C8* self, Rail_0027C2C8* rail, int a, int b, int c, int d);
extern "C" void func_002823A8(Skater_0027C2C8* self, int node);

void Skater_0027C2C8::Respawn(bool air, Rail_0027C2C8* rail, int node)
{
    func_0027C640(this);
    if (air) {
        func_0027C720(this, 0);
        m9C = 0;
    } else {
        func_0027C720(this, 1);
        m9C = 1;
        m5B0->m114.Set(1);
        if (m5BC->mC0)
            m5B0->mFC.Set(1);
    }
    m98 = func_0010FC30();
    mC->GetMatrix(m20);
    m60 = m80 = m70 = mC->m70.r[1];
    mC->m60 = mA0 = mC->m50;
    m374 = 1;
    m219 = 0;
    m354 = 0;
    m3F0 = 0;
    m420 = 0;
    m3D4 = 0;
    m370 = 0;
    m5B0->m150 = 0;
    m430 = 1.0f;
    m3B4 = 0;
    m580 = 0;
    m584 = 0;
    m588 = 0;
    if (rail) {
        m5B4->Clear();
        int id = rail->m18;
        if (id) {
            Holder_0027C2C8* h = m5B4;
            h->Clear();
            h->m1C = (Thing_0027C2C8*)func_0020A6C0(func_0010A638(D_00388A70, 0xC0, 1, 0), id);
        }
        func_0028AAF8(this, rail, rail->m14, rail->m10, 1, 1);
        mC->m60 = mA0 = mC->m50;
        return;
    }
    if (node)
        func_002823A8(this, node);
}
