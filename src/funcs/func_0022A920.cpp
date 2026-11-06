extern int D_0038FBFC;
extern int D_0038881C;
extern char D_00372690[];
extern char D_003726A8[];
extern char D_003726C0[];
extern char D_003726D8[];

struct Pad_0022A920 {
    char pad0[0x13];
    unsigned char m13;
    unsigned char m14;
    unsigned char m15;
    unsigned char m16;
    char pad17[5];
    unsigned int m_held;
    unsigned int m_pressed;
};

struct Ctrl_0022A920 {
    char pad0[0x30];
    float m30;
    float m34;
    char pad38[8];
    float m40;
    float m44;
    char pad48[8];
    unsigned int m_flags;
    char pad54[4];
    int m_mode;
};

extern "C" bool func_001E5628(unsigned int key, int a);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

class Input_0022A920 {
public:
    char pad0[0x1C];
    Pad_0022A920* m_pad;
    char pad20[0xC];
    Ctrl_0022A920* m_ctrl;
    void Update();
};

void Input_0022A920::Update()
{
    Ctrl_0022A920* c = m_ctrl;
    if (!D_0038FBFC)
        return;
    c->m30 = m_pad->m13 - 0x80;
    c->m34 = m_pad->m14 - 0x80;
    c->m40 = m_pad->m15 - 0x80;
    c->m44 = m_pad->m16 - 0x80;
    if (!func_001E5628(0x89BEF647, 1))
        return;
    if (m_pad->m_held & 8) {
        if (m_pad->m_pressed & 2) {
            if (!D_0038881C)
                c->m_flags |= 0x1000;
        } else if (!(m_pad->m_held & 2)) {
            c->m_flags |= 2;
        }
    } else if (m_pad->m_held & 2) {
        c->m_flags |= 4;
    }
    if (m_pad->m_pressed & 0x800)
        c->m_flags |= 0x800;
    if (c->m_mode == 0) {
        if (m_pad->m_pressed & 0x10)
            c->m_flags |= 0x400;
        if (m_pad->m_pressed & 0x80)
            c->m_flags |= 0x100;
        if (m_pad->m_pressed & 0x20)
            c->m_flags |= 0x200;
        if (m_pad->m_pressed & 0x40)
            c->m_flags |= 0x80;
    } else if (c->m_mode == 1) {
        if (m_pad->m_pressed & 0x40)
            c->m_flags |= 0x8000;
    }
    if ((m_pad->m_held & 0x1000) && (m_pad->m_pressed & 0x1000))
        c->m_flags |= 0x10;
    if ((m_pad->m_held & 0x4000) && (m_pad->m_pressed & 0x4000))
        c->m_flags |= 8;
    if (m_pad->m_held & 0x2000)
        c->m_flags |= 0x40;
    if (m_pad->m_held & 0x8000)
        c->m_flags |= 0x20;
    if (m_pad->m_pressed & 0x200)
        c->m_flags |= 0x4000;
    unsigned int h = m_pad->m_held;
    if (h & 4) {
        if (!(h & 1))
            c->m_flags |= 0x10000;
    } else if (h & 1) {
        c->m_flags |= 0x20000;
    }
    if (m_pad->m_held & 0x100)
        return;
    if (m_pad->m_pressed & 0x80)
        func_001F0370(D_00372690, 0, 0, 0);
    if (m_pad->m_pressed & 0x20)
        func_001F0370(D_003726A8, 0, 0, 0);
    if (m_pad->m_pressed & 0x10)
        func_001F0370(D_003726C0, 0, 0, 0);
    if (m_pad->m_pressed & 0x40)
        func_001F0370(D_003726D8, 0, 0, 0);
}
