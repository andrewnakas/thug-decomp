extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern int D_0039429C;
extern int D_0039427C;
extern int D_00394298;
extern int D_003942A0;
extern int D_003940A4;
extern float D_0038C020;
extern int D_0038C02C;
extern float D_003940AC;

struct Vec_0015B200 {
    float x, y, z, w;
};

struct Mat_0015B200;
extern Mat_0015B200 D_003E1100;

struct Pt_0015B200 {
    int m0;
    float m4;
    float m8;
    float mC;
    int m10, m14, m18, m1C;
};

struct Src_0015B200 {
    char pad[0x28];
    long m28;
    long m30;
};

extern "C" int func_00335048();
extern "C" void func_0015F870(Pt_0015B200* p);
extern "C" void func_00323298(Vec_0015B200* out, Mat_0015B200* m, Vec_0015B200* v);
extern "C" void func_001617A0(int a);

static inline void Put_0015B200(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag_0015B200(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Cycle_0015B200(int n)
{
    Put_0015B200(0x01000000 | (n << 8) | n);
    D_0039429C = n;
}

struct C_0015B200 {
    char pad0[0x28];
    float m28;
    float m2C;
    char pad30[0x50];
    Vec_0015B200 m80;
    char pad90[0x10];
    Vec_0015B200 mA0;
    char padB0[0xF0];
    int m1A0;
    int m1A4;
    int m1A8;
    Pt_0015B200* m1AC;
    Pt_0015B200* m1B0;
    Pt_0015B200* m1B4;
    char pad1B8[0x48];
    char m200[0x20];
    long m220;
    char pad228[0x8];
    long m230;
    char pad238[0x1C];
    int m254;
    char pad258[0xB8];
    Src_0015B200* m310;
    void Render();
};

void C_0015B200::Render()
{
    if (m28 != 0.0f && !(m1A0 && m28 == m1B0->m4)) {
        if (m1A8 < m1A4) {
            m1A8++;
            m1B0++;
            if (m1B0 == m1AC + m1A4)
                m1B0 = m1AC;
            m1B0->m4 = m28;
            m1B0->m8 = 1.0f / m28;
            m1B0->mC = 0.0f;
            m1B0->m0 = 0;
            m1B0->m10 = func_00335048();
            m1B0->m14 = func_00335048();
            m1B0->m18 = func_00335048();
            m1B0->m1C = func_00335048();
            m1A0 = 1;
        } else {
            m1A0 = 0;
        }
    } else {
        m1A0 = m28 != 0.0f;
    }
    if (m1A8 == 0)
        return;
    Pt_0015B200* p = m1B4;
    int i;
    for (i = 0; i < m1A8; i++) {
        p->mC += 1.0f / 60.0f;
        p++;
        if (p == m1AC + m1A4)
            p = m1AC;
    }
    if (m1A0)
        m1B0->m0 = (int)(m1B0->mC * m1B0->m4 + 1.0f);
    if (m2C < m1B4->mC) {
        int n = (int)((m1B4->mC - m2C) * m1B4->m4 + 1.0f);
        m1B4->m0 -= n;
        if (m1B4->m0 > 0 || (m1A8 == 1 && m1A0)) {
            m1B4->mC -= (float)n * m1B4->m8;
            func_0015F870(m1B4);
        } else {
            m1A8--;
            m1B4++;
            if (m1B4 == m1AC + m1A4)
                m1B4 = m1AC;
            if (m1A8 == 0)
                return;
        }
    }
    if (m310) {
        m220 = m310->m28;
        m230 = m310->m30;
    }
    Vec_0015B200 v;
    Vec_0015B200 s;
    s.x = m80.x + mA0.x;
    s.y = m80.y + mA0.y;
    s.z = m80.z + mA0.z;
    s.w = m80.w + mA0.w;
    v.x = s.x * 0.5f;
    v.y = s.y * 0.5f;
    v.z = s.z * 0.5f;
    v.w = 1.0f;
    func_00323298(&v, &D_003E1100, &v);
    float f;
    if (v.w > D_0038C020 && D_0038C02C)
        f = D_003940AC * (D_0038C020 / v.w - 1.0f) + 1.0f;
    else
        f = 1.0f;
    m254 = (int)(f * 255.99f) << 24;
    int prev = D_00394298;
    if (D_0039427C != prev)
        func_001617A0(prev);
    unsigned int ad = (unsigned int)m200;
    Tag_0015B200(0x30000011, ad);
    Cycle_0015B200(1);
    unsigned int num = (m1A8 * 2 + 0x11) & 0xFF;
    unsigned int hi = (num << 16) | 0x6C000000;
    unsigned int addr = ((unsigned short)D_00394280 & 0x3FF) | 0x8000;
    Put_0015B200(hi | addr);
    unsigned int* t = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)t;
    D_00394290 = num;
    t[0] = 0x10000000;
    t[1] = 0;
    D_00394274 = (unsigned char*)(t + 2);
    p = m1B4;
    for (i = 0; i < m1A8; i++) {
        if (p == m1AC + m1A4)
            p = m1AC;
        ((float*)D_00394274)[0] = p->mC;
        ((float*)D_00394274)[1] = p->m8;
        ((int*)D_00394274)[2] = p->m0;
        ((int*)D_00394274)[3] = p == m1B0 ? 0x8000 : 0;
        ((int*)D_00394274)[4] = p->m10;
        ((int*)D_00394274)[5] = p->m14;
        ((int*)D_00394274)[6] = p->m18;
        ((int*)D_00394274)[7] = p->m1C;
        D_00394274 += 0x20;
        D_003940A4 += p->m0;
        p++;
    }
    Put_0015B200(0x1400000A);
    D_00394294 = D_00394280;
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
    int next = D_003942A0;
    if (D_0039427C != next)
        func_001617A0(next);
}
