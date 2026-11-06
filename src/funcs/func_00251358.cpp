extern char D_00374BC8[];
extern char D_00374BF0[];
extern char D_00374C10[];
extern char D_00374C30[];
extern char D_00374C60[];
extern char D_00374C88[];
extern char D_00374C98[];
extern char D_00374CA8[];
extern char D_00374CC0[];
extern char D_00374CD0[];
extern char D_00374CE0[];
extern char D_003906B8[];
extern char D_003906C0[];

struct Entry_00251358 {
    int m0;
    int m4[8];
};

extern "C" int func_00103F28(char* fmt, ...);
extern "C" double func_0033ECA8(float x);
extern "C" float func_001000D0(float range);
extern "C" int func_00100080(int n);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int type, int n);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7360(void* p, unsigned int name, unsigned int v);
extern "C" void func_001E9170(void* arr, int i, void* p);
extern "C" void func_001E76D8(void* p, char* name, void* arr);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int in_chrg);
extern "C" void* func_001F0938(char* name, void* params, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void func_001E6AE8(void* p, int in_chrg);
extern "C" void* func_00240850();
extern "C" bool func_0023EBD0(void* p);

static inline float Round(float x)
{
    return (float)(int)(x + 0.499999f);
}

struct Comp_00251358 {
    int m0;
    int m4;
    int m8;
    char padC[0x10];
    Entry_00251358 m1C[7];
    char pad118[0x14];
    float m12C;
    float m130;
    float m134;
    float m138;
    float m13C;
    float m140;
    float m144;
    float m148;
    float m14C[5];
    char pad160[0x14];
    float m174;
    int m178[3];
    int m184;
    int m188;
    void End(int score);
};

extern "C" bool func_00252038(Comp_00251358* self, int i);
extern "C" void func_00251B70(Comp_00251358* self);

void Comp_00251358::End(int score)
{
    if (m184)
        return;
    func_00103F28(D_00374BC8, score);
    func_00103F28(D_00374BF0, func_0033ECA8(m138), func_0033ECA8(m13C), func_0033ECA8(m140));
    float s = (float)score;
    float pts;
    if (s < m138) {
        pts = m12C * s / m138;
    } else if (s < m13C) {
        pts = m12C + (m130 - m12C) * (s - m138) / (m13C - m138);
    } else if (s < m140) {
        pts = m130 + (m134 - m130) * (s - m13C) / (m140 - m13C);
    } else {
        pts = m134 + (100.0f - m134) * (s - m140) / (m140 * 2.0f - m140);
    }
    func_00103F28(D_00374C10, func_0033ECA8(pts));
    pts -= m148;
    func_00103F28(D_00374C30, func_0033ECA8(m148), func_0033ECA8(pts));
    m174 = pts;
    if (pts > 99.9f)
        m174 = 99.9f;
    float var = (99.9f - m174) * 0.1f;
    m174 = m174 + func_001000D0(var * 0.5f);
    if (m174 > 99.9f)
        m174 = 99.9f;
    if (m174 < 0.0f)
        m174 = 0.0f;
    m14C[0] = m174 + func_001000D0(var);
    if (m14C[0] > 99.85f)
        m14C[0] = 99.9f;
    if (m14C[0] < 0.0f)
        m14C[0] = 0.0f;
    m14C[1] = m174 + func_001000D0(var);
    if (m14C[1] > 99.85f)
        m14C[1] = 99.9f;
    if (m14C[1] < 0.0f)
        m14C[1] = 0.0f;
    m14C[2] = m174 * 3.0f - (m14C[0] + m14C[1]);
    if (m14C[2] < 0.0f)
        m14C[2] = 0.0f;
    if (m14C[2] > 99.85f)
        m14C[2] = 99.9f;
    m14C[0] = (int)Round((int)(m14C[0] * 10.0f) * 0.1f + 0.0001f);
    m14C[1] = (int)Round((int)(m14C[1] * 10.0f) * 0.1f + 0.0001f);
    m14C[2] = (int)Round((int)(m14C[2] * 10.0f) * 0.1f + 0.0001f);
    if (m14C[0] > 99.0f)
        m14C[0] = 99.0f;
    if (m14C[1] > 99.0f)
        m14C[1] = 99.0f;
    if (m14C[2] > 99.0f)
        m14C[2] = 99.0f;
    m174 = (int)Round((m14C[0] + m14C[1] + m14C[2]) * 0.33333334f);
    if (m174 > 99.0f)
        m174 = 99.0f;
    m178[m8] = (int)m174;
    func_00103F28(D_00374C60, func_0033ECA8(m14C[0]), func_0033ECA8(m14C[1]), func_0033ECA8(m14C[2]),
                  func_0033ECA8(m174));
    int i;
    for (i = 0; i < 8; i++) {
        if (!m1C[i].m0)
            m1C[i].m4[m8] = m178[m8];
    }
    func_00251B70(this);
    for (i = 0; i < 8; i++) {
        if (!m1C[i].m0)
            m188 = i + 1;
    }
    float lo = m14C[0];
    if (m14C[1] < lo)
        lo = m14C[1];
    if (m14C[2] < lo)
        lo = m14C[2];
    func_00103F28(D_00374C88, func_0033ECA8(lo));
    for (i = 3; i < 5; i++) {
        m14C[i] = lo - var + func_001000D0(var);
        func_00103F28(D_00374C98, i, func_0033ECA8(m14C[i]));
    }
    for (i = 0; i < 5; i++) {
        if (m14C[i] < 0.0f)
            m14C[i] = 0.0f;
    }
    for (i = 0; i < 4; i++) {
        int j = func_00100080(5);
        float t = m14C[i];
        m14C[i] = m14C[j];
        m14C[j] = t;
    }
    if (func_0023EBD0(func_00240850())) {
        void* params = func_001E6978(func_001190D0(8));
        void* arr = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(arr, 5, 10);
        func_00103F28(D_00374CA8);
        for (i = 0; i < 5; i++) {
            void* e = func_001E6978(func_001190D0(8));
            func_001E7268(e, D_003906B8, (int)Round(m14C[i]));
            if (func_00252038(this, i))
                func_001E7360(e, 0, 0x7B1B959F);
            func_001E9170(arr, i, e);
            func_00103F28(D_00374CC0, i, func_0033ECA8(m14C[i]), func_00252038(this, i));
        }
        func_001E76D8(params, D_003906C0, arr);
        func_001E7268(params, D_00374CD0, (int)Round(m174));
        func_001E6518(arr);
        if (arr)
            func_001E8DE8(arr, 3);
        func_001F0938(D_00374CE0, params, 0, 0, -1, 0, 0, 0, 0, 0);
        if (params)
            func_001E6AE8(params, 3);
    }
}
