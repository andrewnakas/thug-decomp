/* fuzzy: 95.0 */
typedef int qword __attribute__((mode(TI)));
union Vec_001F3C98 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001F3C98() {}
    Vec_001F3C98(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

extern "C" float sqrtf(float);
extern "C" int func_00103F28(const char* fmt, ...);
extern char D_003661A0[];
extern char D_003661B8[];
extern char D_003661D0[];
extern char D_0038E930[];

struct Glob_001F3C98 {
    char pad0[0x3B0];
    unsigned int m3B0;
};
extern Glob_001F3C98* D_0038FC78;
extern "C" void* func_0022E358(Glob_001F3C98* g);
extern "C" int func_0024F908(void* p, unsigned int crc);

struct Stats_001F3C98 {
    char pad0[0xC];
    int mC;
    char pad10[0x5C - 0x10];
    int m5C;
};
extern "C" Stats_001F3C98* func_00203360(void* p);
extern "C" int func_00239B88(Stats_001F3C98* s, int a);
extern "C" int func_0023A168(Stats_001F3C98* s, int a, int b, int c, int d);

extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* s, char* name, int v);
extern "C" void func_001E6AE8(void* s, int n);
extern "C" void* func_001F0D78(char* name);
extern "C" void func_001F0210(void* scr, void* params, int a, int b, int c);

struct Body_001F3C98 {
    char pad0[0x50];
    Vec_001F3C98 m50;
};
struct Ctl_001F3C98 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x40 - 0x20];
    int m40;
    char pad44[0xA0 - 0x44];
    int mA0;
};
struct State_001F3C98 {
    char pad0[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
};
struct Info_001F3C98 {
    char pad0[0x34];
    State_001F3C98* m34;
};
struct Goal_001F3C98 {
    unsigned int type;
    int m4;
    int value;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

struct Obj_001F3C98 {
    char pad0[0xC];
    Body_001F3C98* mC;
    char pad10[0x1C - 0x10];
    int m1C;
    Goal_001F3C98 m20[70];
    char pad9F8x[0x9F8 - (0x20 + 70 * 0x24)];
    int m9F8;
    char pad9FC[0xA04 - 0x9FC];
    int mA04;
    int mA08;
    int mA0C;
    int mA10;
    int mA14;
    int mA18;
    char padA1C[0xA28 - 0xA1C];
    unsigned int mA28;
    unsigned int mA2C;
    Vec_001F3C98 mA30;
    Vec_001F3C98 mA40;
    int mA50;
    int mA54;
    int mA58;
    int mA5C;
    float mA60;
    float mA64;
    char padA68[0xA70 - 0xA68];
    Vec_001F3C98 mA70;
    Vec_001F3C98 mA80;
    int mA90;
    int mA94;
    int mA98;
    int mA9C;
    void* mAA0;
    Ctl_001F3C98* mAA4;
    Info_001F3C98* mAA8;
    void Update();
};

extern "C" void func_001F4EA8(Obj_001F3C98* o, int i);

void Obj_001F3C98::Update()
{
    if (!mAA0) return;
    Glob_001F3C98* g = D_0038FC78;
    if (!func_0024F908(func_0022E358(g), 0x1DED1EA4)) return;
    if (!m9F8) return;
    if (g->m3B0 == 0x9F2BAFB7) return;
    if (m1C) {
        mA5C = 0;
        mA90 = 0;
        m1C = 0;
        return;
    }
    Stats_001F3C98* st = func_00203360(mAA0);
    mA04 = st->mC * st->m5C;
    mA14 = st->m5C;
    if (mA14)
        mA0C = mA04 / mA14;
    else
        mA0C = 0;
    int mode = mAA4->m1C;
    mA28 = 0x26A7CADF;
    State_001F3C98* s = mAA8->m34;
    bool ok = !s->m180 && !s->m20;
    if (ok) {
        if (mAA4->m40) {
            mA28 = 0xB39B4F1B;
            if (mA2C != 0xB39B4F1B) {
                mA60 = 0.0f;
                mA5C = 1;
                mA30 = mC->m50;
                mA50 = mA0C;
                mA54 = mA14;
                func_00103F28(D_003661A0, mA04, mA54, mA50);
                mA58 = 0;
            } else {
                Vec_001F3C98 p = mC->m50;
                float d = p[1] - mA30[1];
                if (mA60 < d) mA60 = d;
                int a = (mA0C - mA50) * (mA14 - mA54);
                mA9C = a;
                if (a >= mA58) mA58 = a;
            }
        } else if (mA2C == 0xB39B4F1B) {
            int h = 0;
            if (mA5C == 1) {
                mA5C = 2;
                int w = mA0C - mA50;
                h = mA14 - mA54;
                mA40 = mC->m50;
                mA9C = w * h;
            }
            if (h >= 2 && mA9C) {
                void* params = func_001E6978(func_001190D0(8));
                func_001E7268(params, D_0038E930, mA9C);
                func_001F0210(func_001F0D78(D_003661B8), params, 0, 0, 0);
                if (params) func_001E6AE8(params, 3);
            }
            mA9C = 0;
        } else {
            mA5C = 0;
            mA60 = 0.0f;
            mA58 = 0;
        }
        if (mode == 1 && !mAA4->m40) {
            mA28 = 0x439F4704;
            if (mA2C != 0x439F4704 && !mAA4->mA0) {
                mA90 = mode;
                mA70 = mC->m50;
            }
        } else if (mA2C != 0x439F4704) {
            mA90 = 0;
        } else if (mA90 == 1) {
            mA80 = mC->m50;
            mA90 = 2;
        }
    } else {
        mA90 = 0;
    }
    bool found = false;
    for (int i = 0; i < 70; i++) {
        if (m20[i].type == 0x4EC3CFB5 && !m20[i].m10 && !m20[i].mC && m20[i].value <= mA04) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x5B6556A4 && !m20[i].m10 && !m20[i].mC && m20[i].value <= mA14) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0xC3EC3EED && !m20[i].m10 && !m20[i].mC && mA5C == 2) {
            float lim = m20[i].value * 12.0f;
            mA40[1] = 0.0f;
            mA30[1] = 0.0f;
            Vec_001F3C98 d;
            d[0] = mA40[0] - mA30[0];
            d[1] = mA40[1] - mA30[1];
            d[2] = mA40[2] - mA30[2];
            d[3] = mA40[3] - mA30[3];
            if (lim <= sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2])) {
                func_001F4EA8(this, i);
                found = true;
            }
        }
        if (m20[i].type == 0x430B80C4 && !m20[i].m10 && !m20[i].mC && mA5C && m20[i].value * 12.0f <= mA60) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x1DBBB148 && !m20[i].m10 && !m20[i].mC && mA5C == 2 && m20[i].value <= mA58) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x509ACA95 && !m20[i].m10 && !m20[i].mC && mA5C && m20[i].value <= mA64) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x8F6F9F05 && !m20[i].m10 && !m20[i].mC && mA90 == 2) {
            float lim = m20[i].value * 12.0f;
            Vec_001F3C98 a;
            a.c[0] = mA80.c[0];
            a.c[1] = 0.0f;
            a.c[2] = mA80.c[2];
            Vec_001F3C98 b;
            b.c[0] = mA70.c[0];
            b.c[1] = 0.0f;
            b.c[2] = mA70.c[2];
            a.c[3] = 1.0f;
            b.c[3] = 1.0f;
            Vec_001F3C98 d;
            d[0] = a[0] - b[0];
            d[1] = a[1] - b[1];
            d[2] = a[2] - b[2];
            d[3] = a[3] - b[3];
            if (lim <= sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2])) {
                func_001F4EA8(this, i);
                found = true;
            }
        }
        if (m20[i].type == 0x39E7537B && !m20[i].m10 && !m20[i].mC && mA90 == 2 &&
            m20[i].value * 12.0f <= mA80[1] - mA70[1]) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x7E064AD0 && !m20[i].m10 && !m20[i].mC && mA90 == 2 &&
            m20[i].value * 12.0f <= mA70[1] - mA80[1]) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x364E8C16 && !m20[i].m10 && !m20[i].mC && m20[i].value <= mA94) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x68703AE9 && !m20[i].m10 && !m20[i].mC && m20[i].value <= mA98) {
            func_001F4EA8(this, i);
            found = true;
        }
        if (m20[i].type == 0x9068B4E5 && !m20[i].m10 && !m20[i].mC) {
            int v = m20[i].value;
            if (v <= func_00239B88(st, m20[i].m18)) {
                func_001F4EA8(this, i);
                found = true;
            }
        }
        if (m20[i].type == 0x69B0F836 && !m20[i].m10 && !m20[i].mC) {
            int v = m20[i].value;
            if (v <= func_0023A168(st, m20[i].m1C, 0, 0, m20[i].m20)) {
                func_001F4EA8(this, i);
                found = true;
            }
        }
    }
    if (found) func_001F0210(func_001F0D78(D_003661D0), 0, 0, 0, 0);
    mA64 = 0.0f;
    mA2C = mA28;
    mA08 = mA04;
    mA10 = mA0C;
    mA18 = mA14;
}
