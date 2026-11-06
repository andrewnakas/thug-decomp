typedef int qword_001A9F08 __attribute__((mode(TI)));

struct Vec_001A9F08 {
    union {
        struct { float x, y, z, w; };
        qword_001A9F08 q;
    };
};

struct Mat_001A9F08 {
    Vec_001A9F08 r[4];
};

extern int D_0038A0E8;
extern "C" void func_00323298(Vec_001A9F08* out, Mat_001A9F08* m, Vec_001A9F08* in);
extern "C" int func_001325F0(Vec_001A9F08* p, float r);
extern "C" void func_0013D950(void* skin, int on);

struct Skin_001A9F08 {
    char pad[0x1B0];
    long m1B0;
};

extern "C" Vec_001A9F08 func_0013EF90(Skin_001A9F08* s);

struct RenBase_001A9F08 {
    int m_pad[6];
    virtual void V0();
    virtual void V1();
};

struct Ren_001A9F08 : RenBase_001A9F08 {
    char pad1C[0x260 - 0x1C];
    Skin_001A9F08* m260;
    char pad264[0x288 - 0x264];
    int m288;
};

static inline void Transform_001A9F08(Mat_001A9F08* m, Vec_001A9F08* v)
{
    func_00323298(v, m, v);
}

struct Model_001A9F08 {
    char pad[0xC];
    unsigned int mC;
    char pad10[0x50 - 0x10];
    Vec_001A9F08 m50;
    char pad60[0x10];
    Mat_001A9F08 m70;
};

struct Obj_001A9F08 {
    char pad[0xC];
    Model_001A9F08* mC;
    char pad10[0x28 - 0x10];
    float m28;
    char pad2C[4];
    Ren_001A9F08* m30;
    char pad34[0x40 - 0x34];
    float m40;
    float m44;
    void Method();
};

void Obj_001A9F08::Method()
{
    if (!m30)
        return;
    if (!m30->m260)
        return;
    int vis = 0;
    if (!(mC->mC & 4)) {
        if (m44 == 1000002.0f || D_0038A0E8 >= 2 || m30->m288) {
            vis = 1;
        } else if (m28 < m40 * m40) {
            Vec_001A9F08 cam = func_0013EF90(m30->m260);
            Vec_001A9F08 p = cam;
            p.w = 1.0f;
            Transform_001A9F08(&mC->m70, &p);
            Model_001A9F08* m = mC;
            p.x += m->m50.x;
            p.y += m->m50.y;
            p.z += m->m50.z;
            p.w += m->m50.w;
            vis = func_001325F0(&p, cam.w);
        }
    }
    Skin_001A9F08* sk = m30->m260;
    long f = sk->m1B0;
    int hidden = 0;
    if ((int)(f >> 1) & 1)
        hidden = ((int)(f >> 2) & 1) ^ 1;
    func_0013D950(sk, vis);
    if (vis && !hidden)
        m30->V1();
}
