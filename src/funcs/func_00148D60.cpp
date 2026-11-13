struct Heap_00148D60 {
    char pad[0xD8];
    void* mD8;
    char padDC[0x34];
    void* m110;
};

struct Tex_00148D60 {
    char pad[0xC];
    unsigned short m_width;
    unsigned short m_height;
};

extern Heap_00148D60* D_00388A70;
extern "C" void func_0010A950(Heap_00148D60* heap, void* sub);
extern "C" void* func_0010A638(Heap_00148D60* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00148D60* heap);
extern "C" void func_0010A8D8(Heap_00148D60* heap, void* p);
extern "C" void func_001483D8(Tex_00148D60* tex, void* buf, int x, int y, int w, int h);
extern "C" void func_00148518(Tex_00148D60* tex, void* buf, int x, int y, int w, int h);
extern "C" void func_00147968(void* dst, int x, int y, int w, int h, void* src, int sw, int sh, int bpp);
extern "C" void func_00147A70(void* src, int sw, int sh, void* dst, int dw, int dh, int bpp);

extern "C" int func_00148D60(Tex_00148D60* tex, unsigned short pos, int vertical, int amount)
{
    unsigned short org[2];
    unsigned short sw;
    unsigned short sh;
    unsigned short dw;
    unsigned short dh;
    unsigned short off;
    if (!amount)
        return 1;
    if (pos + amount <= 0)
        amount = -pos + 1;
    if (!vertical) {
        if (pos + amount >= tex->m_width)
            amount = tex->m_width - pos - 1;
        if (amount < 0) {
            org[0] = 0;
            org[1] = 0;
            sh = tex->m_height;
            sw = pos + 1;
            dw = pos - amount + 1;
            off = -amount;
            dh = sh;
        } else {
            org[0] = pos;
            org[1] = 0;
            off = 0;
            sh = tex->m_height;
            sw = tex->m_width - pos;
            dw = tex->m_width - pos + amount;
            dh = sh;
        }
    } else {
        if (pos + amount >= tex->m_height)
            amount = tex->m_height - pos - 1;
        if (amount < 0) {
            org[0] = 0;
            org[1] = 0;
            sw = tex->m_width;
            sh = pos + 1;
            dh = pos - amount + 1;
            off = -amount * sw;
            dw = sw;
        } else {
            org[0] = 0;
            org[1] = pos;
            off = 0;
            sw = tex->m_width;
            sh = tex->m_height - pos;
            dh = tex->m_height - pos + amount;
            dw = sw;
        }
    }
    if (D_00388A70->m110)
        func_0010A950(D_00388A70, D_00388A70->m110);
    else
        func_0010A950(D_00388A70, D_00388A70->mD8);
    unsigned int* sbuf = (unsigned int*)func_0010A638(D_00388A70, sw * sh * 4, 1, 0);
    unsigned int* dbuf = (unsigned int*)func_0010A638(D_00388A70, dw * dh * 4, 1, 0);
    func_0010A9B0(D_00388A70);
    func_001483D8(tex, sbuf, org[0], org[1], sw, sh);
    func_00147A70(sbuf, sw, sh, dbuf, dw, dh, 0x20);
    func_00147968(sbuf, 0, 0, sw, sh, dbuf + off, dw, dh, 0x20);
    func_00148518(tex, sbuf, org[0], org[1], sw, sh);
    if (sbuf)
        func_0010A8D8(D_00388A70, sbuf);
    if (dbuf)
        func_0010A8D8(D_00388A70, dbuf);
    return 1;
}
