struct Color_00298E80 {
    unsigned char r, g, b, a;
};

struct Obj_00298E80;

extern "C" int func_001E53A0(unsigned int name, int v);
extern "C" int func_00298278(void* a, void* b);
extern "C" int func_00299470(Obj_00298E80* o);
extern "C" void func_00134F28(void* model, Color_00298E80* c);
extern "C" void func_00134FD8(void* model, unsigned int v);
extern int D_00391EC8;

struct Obj_00298E80 {
    char pad0[0x10];
    char m10[0x24 - 0x10];
    int m24;
    int m28;
    Obj_00298E80* m2C;
    Obj_00298E80* m30;
    void* m34;
    void* m38;
    void Refresh(int flash, int both);
};

void Obj_00298E80::Refresh(int flash, int both)
{
    if (m24) return;
    unsigned int alpha = 0xFFFFFFFF;
    if (flash) {
        int period = func_001E53A0(0x4551E901, 0);
        int c = D_00391EC8;
        D_00391EC8 = c + 1;
        alpha = c < period / 2 ? 0xFFFFFFFF : 0;
        if (!(c + 1 < period)) D_00391EC8 = 0;
    }
    unsigned char r1 = func_001E53A0(0xAD28B18B, 0);
    unsigned char g1 = func_001E53A0(0xC0F55560, 0);
    unsigned char b1 = func_001E53A0(0xB09FA1EF, 0);
    unsigned char r2 = func_001E53A0(0x89B66FB9, 0);
    unsigned char g2 = func_001E53A0(0xE46B8B52, 0);
    unsigned char b2 = func_001E53A0(0x94017FDD, 0);
    int hl = 0;
    unsigned char r = r1;
    unsigned char g = g1;
    unsigned char b = b1;
    if (m2C) hl = func_00298278(m10, m2C->m10) != 0;
    if (m30) {
        if (func_00298278(m10, m30->m10)) hl = 1;
    }
    Color_00298E80 c;
    if (m38) {
        if (func_00299470(this) && !hl) {
            r = r1; g = g1; b = b1;
        } else {
            r = r2; g = g2; b = b2;
        }
        c.r = r; c.g = g; c.b = b; c.a = 0;
        func_00134F28(m38, &c);
        func_00134FD8(m38, alpha);
    }
    if (m34) {
        if (m2C) {
            if (func_00299470(m2C) && func_00299470(this) && !hl) {
                r = r1; g = g1; b = b1;
            } else {
                r = r2; g = g2; b = b2;
            }
        }
        c.r = r; c.g = g; c.b = b; c.a = 0;
        func_00134F28(m34, &c);
        func_00134FD8(m34, alpha);
    }
    if (m30 && m30->m34) {
        if (func_00299470(m30) && func_00299470(this) && !hl) {
            r = r1; g = g1; b = b1;
        } else {
            r = r2; g = g2; b = b2;
        }
        c.r = r; c.g = g; c.b = b; c.a = 0;
        func_00134F28(m30->m34, &c);
        func_00134FD8(m30->m34, alpha);
    }
    if (both) {
        if (m2C && !m2C->m2C && m2C->m38) {
            c.r = r1; c.g = g1; c.b = b1; c.a = 0;
            func_00134F28(m2C->m38, &c);
            func_00134FD8(m2C->m38, alpha);
        }
        if (m30 && !m30->m30 && m30->m38) {
            c.r = r1; c.g = g1; c.b = b1; c.a = 0;
            func_00134F28(m30->m38, &c);
            func_00134FD8(m30->m38, alpha);
        }
    }
    m24 = 1;
}
