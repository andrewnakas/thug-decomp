extern "C" void* func_00229DF0(int e);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Thing_001B3538 {
    int m_pad[47];
    void* mBC;
};

extern "C" Thing_001B3538* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);

static inline void SetRef_001B3538(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

typedef int qword __attribute__((mode(TI)));

struct C_001B3538 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    int m24[8];
    int m44;
    int m48;
    int m4C;
    qword m50;
    qword m60;
    qword m70;
    int m80;
    int m84;
    void Next();
    void Update();
    void Enter(void* p);
    void Select(void* p);
    void Open(void* p);
};

extern "C" int func_001B3870(C_001B3538* self, int e);

void C_001B3538::Next()
{
    int cur = m48;
    int prev = m44;
    m20 &= ~0x10u;
    m20 &= ~0x20u;
    if (m20 & 8) m20 |= 0x10;
    m20 &= ~0x800u;
    m44 = m48;
    m50 = m60;
    m48 = m4C;
    m60 = m70;
    if (!(m20 & 1) && prev == m48) {
        Thing_001B3538* th = func_001F0750(0xA80F965E, 0, 0, 0, -1, 0, 0, 0, 0, 0);
        SetRef_001B3538(&th->mBC, mC);
    }
    m20 &= ~8u;
    void* s = func_00229DF0(m48);
    m20 &= ~0x8000u;
    unsigned int kind;
    if (func_001E8398(s, 0x17EA37FB, &kind, 0) && kind == 0x54166ACD) {
        unsigned int type;
        func_001E8398(s, 0x963DC198, &type, 1);
        if (func_001B3870(this, m48)) m20 |= 8;
        if (type == 0x7D9D0008 || type == 0x584CF9E9) {
            unsigned int t2;
            if (func_001E8398(func_00229DF0(m44), 0x963DC198, &t2, 1) && t2 != 0x255ED86F
                && !(m20 & 4) && !(m20 & 0x10))
                m20 |= 0x100;
        }
        if (type == 0x554DBD64) m20 |= 0x8000;
    }
    Update();
    if (func_001B3870(this, m4C)) m20 |= 0x20;
    void* ps = func_00229DF0(prev);
    void* cs = func_00229DF0(cur);
    Enter(cs);
    unsigned int t3;
    if (!func_001E8398(ps, 0x963DC198, &t3, 0) || t3 != 0x7D9D0008) {
        unsigned int k2;
        if (func_001E8398(cs, 0x17EA37FB, &k2, 0)) {
            if (k2 != 0x54166ACD) {
                if (k2 == 0x726E85AA) Select(cs);
            } else
                Open(cs);

        }
    }
    m84 = 0;
    m80 = 0;
}
