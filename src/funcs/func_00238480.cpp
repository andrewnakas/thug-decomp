struct Trick_00238480 {
    int m0;
    int m4;
    int m8;
    char padC[0x8];
    int m14;
    unsigned int m18;
};

struct Score_00238480 {
    char pad0[0xC];
    int mC;
    char pad10[0x8];
    int m18;
    int m1C;
    char pad20[0x24];
    char m44[0x14];
    int m58;
    int m5C;
    char pad60[0x8];
    int m68;
    char pad6C[0x18];
    int m84;
    void Tally();
};

extern char D_00373600[];
extern char D_00373610[];
extern char D_00373648[];
extern char D_00373598[];
extern "C" void func_00103F28(char* fmt, ...);
extern "C" Trick_00238480* func_0023AFE8(char* list, int i);
extern "C" int func_002388C0(Score_00238480* s, int v);
extern "C" int func_002388F0(Score_00238480* s, int v);
extern "C" int func_001E5400(char* name, int d);
extern "C" void func_0023AC30(Score_00238480* s, int f);

void Score_00238480::Tally()
{
    if (!m58) {
        m1C = 0;
        m18 = 0;
        return;
    }
    if (m84) func_00103F28(D_00373600);
    int spin = 2;
    mC = 0;
    for (int i = 0; i < m58; i++) {
        if (func_0023AFE8(m44, i)->m18 & 2) {
            spin = 2;
        } else if (i == 0 || (func_0023AFE8(m44, i - 1)->m18 & 2)) {
            spin = func_002388C0(this, func_0023AFE8(m44, i)->m8);
        }
        int red = func_002388F0(this, func_0023AFE8(m44, i)->m4);
        if (m84) {
            Trick_00238480* t = func_0023AFE8(m44, i);
            func_00103F28(D_00373610, t->m0, red * 0.01f, spin * 0.5f);
        }
        int pts = func_0023AFE8(m44, i)->m0 * red * spin / 200;
        if (func_0023AFE8(m44, i)->m14) pts = pts * 120 / 100;
        mC += pts;
    }
    if (m84) func_00103F28(D_00373648, mC);
    if (func_001E5400(D_00373598, 0)) {
        int total = mC * m5C;
        if (m1C < total) {
            m68 += total - m1C;
            if (m68 < 0) {
                func_0023AC30(this, 0);
                m68 = 0;
            }
            if (m68 >= 3000) {
                func_0023AC30(this, 1);
                m68 = 3000;
            }
        }
    }
    m1C = m18 = mC * m5C;
}
