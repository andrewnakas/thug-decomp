typedef int qword __attribute__((mode(TI)));

union Vec_002948A0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_002948A0 {
    Vec_002948A0 pos;
    float a;
    float b;
    char pad18[0x30 - 0x18];
};

struct Obj_002948A0;
extern "C" int func_002932E8(Obj_002948A0* o, Vec_002948A0* p, float a);
extern "C" void func_00292F40(Obj_002948A0* o, int i);
extern "C" void func_00293108(Obj_002948A0* o, int i);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);
extern "C" float func_001E5318(unsigned int, int);

struct Obj_002948A0 {
    char pad0[0x114];
    unsigned int m114;
    char pad118[0x130 - 0x118];
    Node_002948A0 m130[7];
    char pad[0x2A0 - 0x130 - 0x30 * 7];
    unsigned char m2A0;
    unsigned char m2A1;
    unsigned char m2A2;
    unsigned char m2A3;
    bool Place(Vec_002948A0* pos, float a, float b);
};

bool Obj_002948A0::Place(Vec_002948A0* pos, float a, float b)
{
    m2A3 = 0;
    if (!func_002932E8(this, pos, a)) return false;
    m130[m2A2].pos = *pos;
    m130[m2A2].a = a;
    m130[m2A2].b = b;
    if (m2A2 == m2A0 - 1)
        m2A3 = 1;
    if (!m2A2)
        func_001F0210(0xD066A889, 0, 0, 0, 0);
    func_00292F40(this, m2A2);
    m2A2++;
    func_00293108(this, m2A2);
    if (m2A2 < m2A1) return true;
    m2A1 = m2A2;
    if (m2A2 == m2A0) {
        m2A2 = m2A0 - 1;
        return true;
    }
    m130[m2A2].pos = *pos;
    m130[m2A2].a = a;
    m130[m2A2].b = b;
    if ((m114 == 0x4EC3CFB5 || m114 == 0x54166ACD) && m2A2 == 2)
        m130[m2A2].a += func_001E5318(0x082A694E, 0);
    return true;
}
