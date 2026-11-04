typedef int qword __attribute__((mode(TI)));
union Row_0028FB28 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_0028FB28 {
    Row_0028FB28 r[4];
    void Set(const Row_0028FB28& a, const Row_0028FB28& b, const Row_0028FB28& c, const Row_0028FB28& d) {
        r[0] = a;
        r[1] = b;
        r[2] = c;
        r[3] = d;
    }
    Mat_0028FB28& operator=(const Mat_0028FB28& o) {
        Set(o.r[0], o.r[1], o.r[2], o.r[3]);
        return *this;
    }
};

struct Body_0028FB28 {
    char pad[0x70];
    Mat_0028FB28 m70;
    float mB0;
    float mB4;
    float mB8;
    float mBC;
    Mat_0028FB28 mC0;
};

struct Phys_0028FB28 {
    char pad[0xC];
    Body_0028FB28* mC;
    char pad10[0x20 - 0x10];
    Mat_0028FB28 m20;
    Row_0028FB28 m60;
    Row_0028FB28 m70;
    char pad80[0x2D4 - 0x80];
    int m2D4;
};

struct State_0028FB28 {
    char pad[0x1C];
    int m1C;
    char pad20[0x7C - 0x20];
    int m7C;
    char pad80[0xA0 - 0x80];
    int mA0;
    char padA4[0x13C - 0xA4];
    int m13C;
    char pad140[0x150 - 0x140];
    int m150;
    char pad154[0x160 - 0x154];
    Row_0028FB28 m160;
    Row_0028FB28 m170;
    void Check() { if (m1C != 1) m150 = 0; }
};

struct Lnk_0028FB28 {
    char pad[0x20];
    int m20;
    char pad24[4];
    int m28;
};

struct Anim_0028FB28 {
    char pad[0x50];
    int m50;
    int m54;
    char pad58[0x7C - 0x58];
    bool m7C;
    char pad80[4];
    int m84;
    int m88;
    void SetA(int v) { m7C |= m88 != v; m88 = v; }
    void SetB(int v) { m7C |= m50 != v; m50 = v; }
    void SetC(int v) { m7C |= m54 != v; m54 = v; }
};

extern "C" void func_00100DC0(void* m, int axis);
extern "C" int func_001013F0(void* m);
extern "C" void* func_00185578(void*, unsigned int);
extern "C" float func_00203D40(Body_0028FB28* o, unsigned int name);
extern "C" void func_002708F8(Anim_0028FB28* a, float v);
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

struct Obj_0028FB28 {
    char pad[0xC];
    Body_0028FB28* mC;
    char pad10[0x1C - 0x10];
    Phys_0028FB28* m1C;
    State_0028FB28* m20;
    void Update();
};

void Obj_0028FB28::Update()
{
    if (m1C->m2D4 && m20->m1C != 3) {
        m20->m150 = 0;
        if (m20->m1C == 1 && fabsf(mC->mB0) < 1.0f && fabsf(mC->mB8) < 1.0f)
            m20->m150 = 1;
    }
    m20->Check();
    m20->m160 = m1C->m60;
    m20->m170 = m1C->m70;
    func_00100DC0(&mC->m70, 1);
    func_00100DC0(&m1C->m20, 1);
    if (func_001013F0(&mC->m70))
        m1C->m20 = m1C->mC->m70;
    mC->mC0 = m1C->m20;
    Lnk_0028FB28* l = (Lnk_0028FB28*)func_00185578(mC, 0x187574FA);
    l->m28 = m20->m7C;
    l->m20 = m20->m13C;
    Anim_0028FB28* a = (Anim_0028FB28*)func_00185578(mC, 0xB5F1E9D2);
    func_002708F8(a, sqrtf(mC->mB0 * mC->mB0 + mC->mB8 * mC->mB8) / func_00203D40(mC, 0xCC5F87AA));
    a->m84 = m20->mA0;
    a->SetA(m20->m7C);
    a->SetB(m20->m13C);
    a->SetC(m20->m1C);
}
