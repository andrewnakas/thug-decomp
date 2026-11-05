struct Params_002C60A8 {
    int m0;
    int m4;
};

struct Stats_002C60A8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

struct Elem_002C60A8;
struct Ref_002C60A8 {
    Elem_002C60A8* p;
    int m4;
    int m8;
    void Release();
};
extern "C" void func_00183CB8(Elem_002C60A8* p, Ref_002C60A8* r);
inline void Ref_002C60A8::Release()
{
    if (p) {
        func_00183CB8(p, this);
        p = 0;
    }
}

struct Rec_002C60A8 {
    void* m0;
    char pad4[0x94 - 4];
    int m94;
};
struct Link_002C60A8 {
    void* m0;
    Rec_002C60A8* m4;
    void* Rec() { return m4->m0; }
    int Count() { return m4->m94; }
};
struct Ctl_002C60A8 {
    char pad0[0x7C];
    int m7C;
    bool Is6() const { return m7C == 6; }
};
struct Flags_002C60A8 {
    char pad0[0x8];
    unsigned int m8;
};
struct Clock_002C60A8 {
    char pad0[0x34];
    int m34;
};
struct Score_002C60A8 {
    char pad0[0x2C];
    int m2C;
};
struct Glob_002C60A8 {
    char pad0[0xD8];
    Clock_002C60A8* mD8;
    Score_002C60A8* mDC;
};

extern Glob_002C60A8* D_00388A70;
extern void* D_00389A30;
extern char D_00392818[];
extern char D_0037A9D8[];
extern char D_0037A9E8[];
extern char D_0037A9F8[];
extern char D_0037AA10[];
extern char D_0037AA20[];
extern char D_0037AA30[];
extern char D_0037AA40[];
extern char D_0037AA50[];
extern char D_0037AA70[];
extern char D_0037AA88[];
extern char D_0037AAA8[];
extern char D_0037AAC0[];
extern char D_0037AAD8[];
extern char D_0037AAF8[];
extern char D_0037AB08[];
extern char D_0037AB20[];

extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int n);
extern "C" void func_001E7360(void* s, int a, unsigned int v);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_002149A8(void* s, int a);
extern "C" void func_00214A88(int a, int b);
extern "C" Flags_002C60A8* func_0029C320();
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" void func_001F0938(char* s, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_002B74F0(Stats_002C60A8* st, void* rec, int a);
extern "C" int func_002B73B8(void* rec, char* name);
extern "C" int func_0010C258(int a);
extern "C" void func_0012DB48(Ref_002C60A8* r, void* root, unsigned int name, int a);
extern "C" void func_00123DB0(Elem_002C60A8* e, float a, float b, int c, int d);
extern "C" int func_001E53A0(unsigned int name, int a);
extern "C" char* func_001044A8(int v, int c);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001262A0(Elem_002C60A8* e, char* s);
extern "C" int func_0033ECA8(float f);

static inline void Raise_002C60A8(float& m, float v)
{
    if (m < v)
        m = v;
}

struct Game_002C60A8 {
    char pad0[0x34];
    int m34;
    int m38;
    char pad3C[0x60 - 0x3C];
    int m60;
    char pad64[0x7C - 0x64];
    Link_002C60A8 m7C;
    char pad84[0xA0 - 0x84];
    Ctl_002C60A8* mA0;
    char padA4[0xAC - 0xA4];
    unsigned int mAC;
    int mB0;
    float mB4;
    void Update();
    void Finish(int a);
    void Run6();
    void RunOther();
};

extern "C" void func_002C6A40(Game_002C60A8* g, int a);
extern "C" void func_002C6080(Game_002C60A8* g);
extern "C" void func_002C5628(Game_002C60A8* g);

void Game_002C60A8::Update()
{
    if (!mB0) {
        if (mAC == 0x7ECA21E5) {
            Params_002C60A8 prm;
            func_001E6978(&prm);
            func_001E7360(&prm, 0, func_001F0D78(D_00392818));
            func_002149A8(&prm, 0);
            func_001E6AE8(&prm, 2);
        } else if (mAC == 0xA40F0B8A) {
            func_00214A88(0, 0);
        }
    }
    if (mAC == 0x7ECA21E5 && mA0) {
        if (mB0)
            return;
        if (mA0->Is6()) {
            if (func_0029C320()->m8 & 1)
                func_001F0210(0x2C3B17EA, 0, 0, 0, 0);
            func_002C6080(this);
            if (!mA0->Is6())
                func_001F0210(0x32428A49, 0, 0, 0, 0);
        } else {
            if ((func_0029C320()->m8 & 1) == 0)
                func_001F0210(0x32428A49, 0, 0, 0, 0);
            func_002C5628(this);
            if (mA0->Is6())
                func_001F0210(0x2C3B17EA, 0, 0, 0, 0);
        }
        if (mB0)
            return;
        Stats_002C60A8 st;
        Ref_002C60A8 r;
        char b1[128];
        char b2[128];
        char b3[128];
        char b4[128];
        char b5[128];
        char b6[128];
        char b7[128];
        void* rec = m7C.Rec();
        func_002B74F0(&st, rec, 0);
        if (st.mC >= 0)
            mB4 = 1.0f - (float)st.mC / (float)func_002B73B8(rec, D_0037A9D8);
        else
            mB4 = 1.0f;
        Clock_002C60A8* clk = D_00388A70->mD8;
        Score_002C60A8* sc = D_00388A70->mDC;
        Raise_002C60A8(mB4, 2.0f - (float)func_0010C258(clk->m34) * 9.999999975e-07f);
        Raise_002C60A8(mB4, 1.0f - (float)st.m4 / (float)func_002B73B8(rec, D_0037A9E8));
        m34 = st.mC;
        int sum = st.m20 * 7 + st.m18 * 9 + st.m1C;
        int lo = func_002B73B8(rec, D_0037A9F8);
        Raise_002C60A8(mB4, (float)(sum - lo) / (float)(func_002B73B8(rec, D_0037AA10) - lo));
        int sum2 = (st.m20 + st.m18) * 2;
        int lo2 = func_002B73B8(rec, D_0037AA20);
        Raise_002C60A8(mB4, (float)(sum2 - lo2) / (float)(func_002B73B8(rec, D_0037AA30) - lo2));
        int n = m7C.Count();
        Raise_002C60A8(mB4, (float)n / (float)func_002B73B8(rec, D_0037AA40));
        float f = mB4;
        if (f < 0.0f)
            f = 0.0f;
        else if (1.0f < f)
            f = 1.0f;
        bool ok = false;
        if (mA0->Is6())
            m38 = 0;
        if (1.0f <= f && func_0010C258(clk->m34) < 1000000 && sc->m2C + func_0010C258(clk->m34) > 1002000)
            ok = m38 != 0;
        m38 = 0;
        if (ok) {
            func_002C6A40(this, 1);
            func_001F0938(D_0037AA50, 0, 0, 0, -1, 0, 0, 0, 0, 0);
            return;
        }
        func_0012DB48(&r, D_00389A30, 0xCD9C729A, 0);
        Elem_002C60A8* e = r.p;
        r.Release();
        if (e)
            func_00123DB0(e, f, 1.0f, 0, 1);
        if (func_001E53A0(0x7A9C1ACD, 0)) {
            func_001F0210(0xB935948D, 0, 0, 0, 0);
            void* root = D_00389A30;
            func_0012DB48(&r, root, 0xA5A33EB9, 1);
            Elem_002C60A8* e1 = r.p;
            r.Release();
            func_003331D0(b1, D_0037AA70, func_001044A8(st.m4, 0x2C));
            func_001262A0(e1, b1);
            func_0012DB48(&r, root, 0xCD38C218, 1);
            Elem_002C60A8* e2 = r.p;
            r.Release();
            if (st.m14)
                func_003331D0(b2, D_0037AA88, func_001044A8(st.mC, 0x2C));
            else
                func_003331D0(b2, D_0037AAA8, func_001044A8(st.mC, 0x2C));
            func_001262A0(e2, b2);
            func_0012DB48(&r, root, 0x9DD4532F, 1);
            Elem_002C60A8* e3 = r.p;
            r.Release();
            func_003331D0(b3, D_0037AAC0, st.m8 - st.m10);
            func_001262A0(e3, b3);
            func_0012DB48(&r, root, 0xB42704A3, 1);
            Elem_002C60A8* e4 = r.p;
            r.Release();
            func_003331D0(b4, D_0037AAD8, func_002B73B8(rec, D_0037AA10) - sum - lo, func_002B73B8(rec, D_0037AA30) - sum2 - lo2);
            func_001262A0(e4, b4);
            func_0012DB48(&r, root, 0x65F2394F, 1);
            Elem_002C60A8* e5 = r.p;
            r.Release();
            func_003331D0(b5, D_0037AAF8, func_0033ECA8(mB4 * 100.0f));
            func_001262A0(e5, b5);
            func_0012DB48(&r, root, 0x3DA56DAC, 1);
            Elem_002C60A8* e6 = r.p;
            r.Release();
            func_003331D0(b6, D_0037AB08, func_002B73B8(rec, D_0037AA40) - m7C.Count());
            func_001262A0(e6, b6);
            func_0012DB48(&r, root, 0xF95160C8, 1);
            Elem_002C60A8* e7 = r.p;
            r.Release();
            func_003331D0(b7, D_0037AB20, func_001044A8(st.m8, 0x2C));
            func_001262A0(e7, b7);
        } else {
            func_001F0210(0x7A449180, 0, 0, 0, 0);
        }
    } else {
        m60 = 0;
    }
}
