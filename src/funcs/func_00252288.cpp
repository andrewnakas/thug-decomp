extern char D_00390740[];
extern char D_00390748[];
extern char D_00374D60[];
extern char D_00374D70[];
extern char D_00374D88[];
extern char D_00374D98[];
extern char D_00374DB0[];
extern char D_00374DC8[];
extern unsigned int D_00354DC0[];
extern unsigned int D_00354DC4[];
extern unsigned int D_00354DC8[];
extern unsigned int D_00354DCC[];
extern unsigned int D_00354DD4[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" char* func_001E5518(const char* name, int a);
extern "C" char* func_001044A8(int v, int sep);
extern "C" char* func_00331A9C(char* dst, const char* src);

struct Obj_00252288;
extern "C" int func_00252780(Obj_00252288* self, int a);
extern "C" void func_00252B60(Obj_00252288* self);
extern "C" int func_00252528(Obj_00252288* self);

struct Obj_00252288 {
    int m0;
    int m4;
    int m8;
    int mC;
    char m10[0x200];
    char m210[0x200];
    int m410[8];
    char pad430[8];
    unsigned int m438;
    void Fn();
};

void Obj_00252288::Fn()
{
    func_003331D0(m210, D_00390740);
    mC = m8;
    int n = func_00252780(this, m8);
    func_00103F28(D_00374D60, n);
    if (m4 < n) {
        m4 = n;
        func_003331D0(m210, D_00390748, func_001E5518(D_00374D70, 0), func_001044A8(m4, 0x2C));
        m438 = D_00354DC8[0];
    } else if (n < m4) {
        m4 = 0;
        m410[m8]++;
        func_00252B60(this);
        if (func_00252528(this)) {
            func_003331D0(m210, D_00374D88, m10);
            m438 = D_00354DCC[0];
        } else {
            unsigned char c[2];
            c[0] = m10[m410[m8] - 1];
            if (c[0] >= 'a' && c[0] <= 'z') {
                c[0] -= 'a';
                c[0] += 'A';
            }
            c[1] = 0;
            func_003331D0(m210, D_00390748, func_001E5518(D_00374D98, 0), c);
            m438 = D_00354DC0[0];
        }
    } else if (n == 0) {
        func_00331A9C(m210, func_001E5518(D_00374DB0, 0));
        m438 = D_00354DD4[0];
    } else {
        func_00331A9C(m210, func_001E5518(D_00374DC8, 0));
        m438 = D_00354DC4[0];
    }
}
