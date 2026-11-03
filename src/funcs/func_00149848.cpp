struct Heap_00149848 {
    char pad[0xD8];
    void* mD8;
};

struct Img_00149848 {
    char pad[0x10];
    unsigned char* m_pixels;
    void* m_tex;
};

struct Tex_00149848 {
    char pad[0xC];
    unsigned short m_width;
    unsigned short m_height;
    unsigned char m_depth;
    char pad11[0xB];
    Img_00149848* m_img;
    char pad20[0x8];
    unsigned char* m_palPixels;
};

extern Heap_00149848* D_00388A70;
extern "C" void func_0010A950(Heap_00149848* heap, void* sub);
extern "C" void* func_0010A638(Heap_00149848* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00149848* heap);
extern "C" void func_0010A8D8(Heap_00149848* heap, void* p);
extern "C" void func_001483D8(Tex_00149848* tex, void* buf, int x, int y, int w, int h);
extern "C" void func_00148518(Tex_00149848* tex, void* buf, int x, int y, int w, int h);
extern "C" void func_00160D18(void* tex, void* buf, int w, int h, int bpp, int colors);

extern "C" int func_00149848(Tex_00149848* dst, Tex_00149848* src, int upload)
{
    unsigned char* dbuf = 0;
    unsigned char* sbuf = 0;
    bool paletted = dst->m_depth < 9;
    unsigned char* d;
    unsigned char* s;
    if (paletted) {
        d = dst->m_palPixels;
        s = src->m_palPixels;
        func_0010A950(D_00388A70, D_00388A70->mD8);
        if (!d) {
            dbuf = (unsigned char*)func_0010A638(D_00388A70, dst->m_width * dst->m_height * 4, 1, 0);
            func_001483D8(dst, dbuf, 0, 0, dst->m_width, dst->m_height);
            d = dbuf;
        }
        if (!s) {
            sbuf = (unsigned char*)func_0010A638(D_00388A70, src->m_width * src->m_height * 4, 1, 0);
            func_001483D8(src, sbuf, 0, 0, src->m_width, src->m_height);
            s = sbuf;
        }
        func_0010A9B0(D_00388A70);
    } else {
        s = src->m_img->m_pixels;
        d = dst->m_img->m_pixels;
    }
    int n = dst->m_width * dst->m_height;
    for (int i = 0; i < n; i++, s += 4, d += 4) {
        unsigned char inv = 0x80 - s[3];
        int r = d[0] * inv;
        int g = d[1] * inv;
        int b = d[2] * inv;
        unsigned char a = d[3];
        d[0] = (s[0] * s[3] + r) >> 7;
        d[1] = (s[1] * s[3] + g) >> 7;
        d[2] = (s[2] * s[3] + b) >> 7;
        d[3] = s[3] < a ? a : s[3];
    }
    if (paletted && !dst->m_palPixels) {
        if (upload)
            func_00160D18(dst->m_img->m_tex, dbuf, dst->m_width, dst->m_height, 0x20, 1 << dst->m_depth);
        func_00148518(dst, dbuf, 0, 0, dst->m_width, dst->m_height);
    }
    if (dbuf)
        func_0010A8D8(D_00388A70, dbuf);
    if (sbuf)
        func_0010A8D8(D_00388A70, sbuf);
    return 0;
}
