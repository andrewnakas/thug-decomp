struct Trick_00237100 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    unsigned int m14;
    int m18;
    char m1C[0x40];
    char m5C[0x40];
};

struct Count_00237100 {
    int m0;
    int m4[4];
    int m14[4];
};

struct List_00237100 {
    int pad0;
    int m_count;
};

struct Arr_00237100 {
    int pad0;
};

struct Pool_00237100 {
    char pad[0xE4];
    int mE4;
};

struct Comp_00237100 {
    char padC[0xC];
    void* mC;
    char pad10[0xC];
    int m1C;
    float m20;
    short m24;
};

struct Flag_00237100 {
    char pad[0x20];
    int m20;
};

struct Rec_00237100 {
    char pad[0x13F4];
    int m13F4;
};

struct Obj_00237100 {
    short pad0;
    short m_id;
    int m4;
    int m8;
    int mC;
    char pad10[0x1C];
    List_00237100 m2C;
    char pad34[0x10];
    Arr_00237100 m44;
    char pad48[0x10];
    int m58;
    int m5C;
    int m60;
    int m64;
    char pad68[0x1C];
    int m84;
    void Add(char* name, int score, unsigned int flags);
};

extern void* D_0038FC78;
extern Pool_00237100* D_00388A70;
extern char D_00373480[];
extern char D_003734A0[];
extern char D_003734B0[];
extern char D_003734C0[];
extern char D_0038FE48[];
extern char D_0038FE50[];

extern "C" void* func_0022DF08(void* mgr, int id);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_001F4838(void* a, char* name, int score, int b);
extern "C" void func_00236778(Obj_00237100* obj);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" Trick_00237100* func_0023B0A0(Arr_00237100* a);
extern "C" void func_00238480(Obj_00237100* obj);
extern "C" void func_0010A950(Pool_00237100* p, int a);
extern "C" unsigned int func_001F0D78(char* name);
extern "C" int func_0023B000(Arr_00237100* a);
extern "C" void* func_0010A638(Pool_00237100* p, int size, int a, int b);
extern "C" void func_0023B0C0(Arr_00237100* a, void* p);
extern "C" void func_00236D50(Obj_00237100* obj, char* dst, char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" Trick_00237100* func_0023AFE8(Arr_00237100* a, int i);
extern "C" int func_00331BB8(char* s);
extern "C" char* func_00331678(char* d, char* s);
extern "C" Count_00237100* func_0023B1C0(List_00237100* l, const int& key);
extern "C" void func_0023B220(List_00237100* l, const int& key, Count_00237100* c);
extern "C" float func_00203D40(void* a, unsigned int key);
extern "C" void func_00184920(void* a, unsigned int key, float b, int c);
extern "C" void func_00238780(Obj_00237100* obj, int a);
extern "C" int func_002041F8(void* sk);
extern "C" void func_00236E00(Obj_00237100* obj, int a);
extern "C" void func_00238EF8(Obj_00237100* obj, int score, int mult);
extern "C" void func_0010A9B0(Pool_00237100* p);

void Obj_00237100::Add(char* name, int score, unsigned int flags)
{
    int empty = 0;
    if (!*name)
        empty = 1;
    void* sk = func_0022DF08(D_0038FC78, m_id);
    Rec_00237100* rec = (Rec_00237100*)func_00185578(sk, 0x270F56E1);
    void* c2 = func_00185578(sk, 0x4FF8DAC6);
    if (name && *name)
        rec->m13F4 = 1;
    func_001F4838(c2, name, score, 0);
    if (m58 >= 250) {
        func_00236778(this);
        if (m58 >= 250) {
            if (!empty) {
                func_00103F28(D_00373480, 250);
                func_0023B0A0(&m44)->m0 += score;
                m5C++;
                func_00238480(this);
            }
            return;
        }
    }
    func_0010A950(D_00388A70, D_00388A70->mE4);
    unsigned int id = func_001F0D78(name);
    unsigned int idx = (flags & 0xC) >> 1;
    if (func_0023B000(&m44) < 250) {
        func_0023B0C0(&m44, func_0010A638(D_00388A70, 0x9C, 1, 0));
        func_0023B0A0(&m44)->m0 = 0;
    }
    func_0023B0A0(&m44)->m0 += score;
    func_0023B0A0(&m44)->m10 = id;
    func_0023B0A0(&m44)->m14 = idx;
    func_0023B0A0(&m44)->m18 = flags;
    func_0023B0A0(&m44)->m8 = 0;
    func_0023B0A0(&m44)->m1C[0] = 0;
    func_0023B0A0(&m44)->m5C[0] = 0;
    func_0023B0A0(&m44)->mC = 0;
    if (!empty) {
        func_00236D50(this, func_0023B0A0(&m44)->m1C, name);
        if (flags & 0x80)
            func_003331D0(func_0023B0A0(&m44)->m5C, D_003734A0, func_0023B0A0(&m44)->m1C);
        else if (flags & 0x20)
            func_003331D0(func_0023B0A0(&m44)->m5C, D_003734B0, func_0023B0A0(&m44)->m1C);
        else
            func_003331D0(func_0023B0A0(&m44)->m5C, D_0038FE48, func_0023B0A0(&m44)->m1C);
        for (int i = func_0023B000(&m44) - 2; i >= 0; i--) {
            Trick_00237100* t = func_0023AFE8(&m44, i);
            char* s = t->m5C;
            int len = func_00331BB8(s);
            if (t->m5C[0] == '.' || !len)
                continue;
            if (s[len - 1] == ' ')
                s[len - 1] = 0;
            func_00331678(s, D_0038FE50);
            break;
        }
    }
    if (m60 == m58 - 1)
        m64 = m58;
    if (flags & 2)
        m60 = m58;
    if (!(flags & 0x50)) {
        List_00237100* l = &m2C;
        Count_00237100* c = func_0023B1C0(l, id);
        if (!c) {
            c = (Count_00237100*)func_0010A638(D_00388A70, 0x24, 1, 0);
            func_0023B220(l, id, c);
            for (int j = 0; j < 4; j++) {
                c->m4[j] = 0;
                c->m14[j] = 0;
            }
        }
        func_0023B0A0(&m44)->m4 = c->m4[idx] + c->m14[idx]++;
    } else {
        func_0023B0A0(&m44)->m4 = 0;
    }
    m58++;
    if (!empty) {
        int old = m5C;
        m5C = old + 1;
        if (m5C == 1) {
            Comp_00237100* cp = (Comp_00237100*)func_00185578(sk, 0x8BCE7E66);
            float v = func_00203D40(cp->mC, 0x0B84F532);
            cp->m24 = 0;
            cp->m20 = v;
            cp->m1C = 2;
            func_00184920(sk, 0x670FDA8C, 0.0f, 0);
        }
        int n = 0;
        for (int k = m58 - 1; k > 0 && !(func_0023AFE8(&m44, k)->m18 & 2); k--)
            n++;
        if (n >= 11) {
            func_0023B0A0(&m44)->m0 = 0;
            m5C--;
        }
        Flag_00237100* fl = (Flag_00237100*)func_00185578(sk, 0x9F9CC949);
        if (fl && fl->m20) {
            func_0023B0A0(&m44)->m0 = 0;
            m5C = old;
        }
    }
    if (m84)
        func_00103F28(D_003734C0, name);
    func_00238480(this);
    func_00238780(this, 0);
    func_00236E00(this, func_002041F8(sk));
    m8 = 0;
    func_00238EF8(this, mC, m5C);
    func_0010A9B0(D_00388A70);
}
