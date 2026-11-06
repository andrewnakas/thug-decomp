extern "C" void* memcpy(void*, const void*, unsigned int);

struct Text7_00236778 {
    int w[2];
};
struct Text9_00236778 {
    int w[3];
};
extern Text7_00236778 D_0038FE40[];
extern Text9_00236778 D_003733B0[];

struct Trick_00236778 {
    int m_score;
    unsigned int m_name;
    unsigned int m_category;
    int mC;
    int m10;
    int m_switch;
    unsigned int m_flags;
    char m_text[0x40];
    char m_text2[0x40];
};

struct Log_00236778;
extern "C" Trick_00236778* func_0023AFE8(Log_00236778* log, int index);
extern "C" int func_0023B000(Log_00236778* log);
extern "C" void func_0023B008(Log_00236778* log, int index);

struct Score_00236778;
extern "C" int func_00236608(Score_00236778* self, int start, int end);

struct Log_00236778 {
    int m0;
    int Count() { return func_0023B000(this); }
    Trick_00236778* Get(int i) { return func_0023AFE8(this, i); }
    void RemoveAt(int i) { func_0023B008(this, i); }
};

struct Score_00236778 {
    char pad[0x44];
    Log_00236778 m_log;
    char pad48[0x58 - 0x48];
    int m_58;
    int m5C;
    int m_60;
    int m_64;
    void Collapse();
};

void Score_00236778::Collapse()
{
    Trick_00236778 t;
    memcpy(t.m_text, D_0038FE40, 7);
    memcpy(t.m_text2, D_003733B0, 9);
    t.m_score = 0;
    t.m10 = 0;
    t.m_switch = 0;
    t.m_flags = 0;
    t.m_name = 0;
    t.m_category = 0;
    t.mC = 0;

    int n = m_log.Count();
    for (int i = 0; i < m_log.Count(); i++) {
        if (i && !m_log.Get(i)->m_text[0]) {
            n = i;
            break;
        }
    }
    if (m_64 < n)
        return;
    if (m_60 < n)
        return;
    t.m_score = func_00236608(this, 0, n);
    for (int i = 0; i < n; i++) {
        m_log.RemoveAt(1);
        m_58--;
        m_64--;
        m_60--;
    }
    *m_log.Get(0) = t;
    m_log.Get(0)->m_flags |= 2;
}
