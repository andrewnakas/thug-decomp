/* near miss: 19 words: only $s4/$s5 swapped between the 180 const/deg pseudo (game s4) and 'angle' (game s5). NOTE: replacing 'angle = spins;' by a fresh copy 'int n = a / 180; ...->m_angle = angle; int spins = n;' (n only for the final m_spins store) gives a full MATCH, but that is an alias temporary (rejected style) - lead to decide. */
struct Trick_00237728 {
    char pad[8];
    int m_spins;
    int m_angle;
    unsigned int m_type;
    char pad14[4];
    unsigned int m_flags;
    char m_name[0x40];
    char m_text[0x40];
};

extern void* D_0038FC78;
extern char D_0038FE60[];
extern char D_0038FE68[];
extern char D_003734D8[];
extern char D_003734F0[];
extern char D_00373508[];
extern char D_00373520[];
extern char D_00373530[];
extern char D_00373548[];
extern char D_00373560[];
extern "C" void* func_0022DF08(void* game, int id);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001A2CE0(void* comp);
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" Trick_00237728* func_0023AFE8(void* list, int index);
extern "C" int func_0023B000(void* list);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001F4FA0(void* comp, float f);
extern "C" void func_00184920(void* obj, unsigned int name, float f, int a);

struct Combo_00237728 {
    short m0;
    short m2;
    char pad4[4];
    int m8;
    int mC;
    char pad10[0x44 - 0x10];
    char m_list[0x14];
    int m58;
    int m5C;
    char pad60[4];
    int m64;
    char pad68[0x84 - 0x68];
    int m84;
    void Spin(int angle);
};

extern "C" void func_00238780(Combo_00237728* self, int a);
extern "C" void func_00238480(Combo_00237728* self);
extern "C" void func_00238EF8(Combo_00237728* self, int a, int b);

void Combo_00237728::Spin(int angle)
{
    if (!m58) {
        return;
    }
    if (m64 < 0) {
        return;
    }
    int a = angle;
    void* sk = func_0022DF08(D_0038FC78, m2);
    int flip = func_001A2CE0(func_00185578(sk, 0x72AD7B23));
    const char* dir;
    if (angle < 0) {
        a = -angle;
        if (flip) {
            dir = D_0038FE60;
        } else {
            dir = D_0038FE68;
        }
    } else {
        if (flip) {
            dir = D_0038FE68;
        } else {
            dir = D_0038FE60;
        }
    }
    a += (int)func_002032A0(0x50C5CC2F, 0);
    int spins = a / 180;
    func_0023AFE8(m_list, m64)->m_angle = angle;
    if (func_0023AFE8(m_list, m64)->m_spins < spins) {
        if (m84) {
            func_00103F28(D_003734D8, spins * 180);
        }
        if (func_0023AFE8(m_list, m64)->m_type == 0x9B65D7B8 && spins / 2 * 2 == spins - 1) {
            if (dir == D_0038FE68) {
                dir = D_0038FE60;
            } else {
                dir = D_0038FE68;
            }
        }
        const char* fmt;
        int last = func_0023B000(m_list) - 1;
        int deg = spins * 180;
        if (m64 < last) {
            if (func_0023AFE8(m_list, m64)->m_flags & 0x80) {
                fmt = D_003734F0;
            } else if (func_0023AFE8(m_list, m64)->m_flags & 0x20) {
                fmt = D_00373508;
            } else {
                fmt = D_00373520;
            }
        } else {
            if (func_0023AFE8(m_list, m64)->m_flags & 0x80) {
                fmt = D_00373530;
            } else if (func_0023AFE8(m_list, m64)->m_flags & 0x20) {
                fmt = D_00373548;
            } else {
                fmt = D_00373560;
            }
        }
        func_003331D0(func_0023AFE8(m_list, m64)->m_text, fmt, dir, deg, func_0023AFE8(m_list, m64)->m_name);
        func_00238780(this, 0);
        func_0023AFE8(m_list, m64)->m_spins = spins;
        func_00238480(this);
        func_001F4FA0(func_00185578(sk, 0x4FF8DAC6), spins * 180);
        m8 = 0;
        func_00238EF8(this, mC, m5C);
        func_00184920(sk, 0x68B887BB, 0.0f, 0);
    }
}
