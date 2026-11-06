/* fuzzy: 90.7 */
struct Glyph_00172A28 {
    unsigned short x0;
    unsigned short y0;
    unsigned short x1;
    unsigned short y1;
    unsigned short base;
};

struct Entry_00172A28 {
    unsigned short a;
    short c;
};

struct Font_00172A28 {
    int m0;
    int m4;
    Glyph_00172A28* m_glyphs;
    unsigned char m_map[256];
    unsigned char m_map2[31];
    unsigned char m_default;
    void* m_data;
    int m_size;
    int pad134;
    unsigned long m_tex0;
    unsigned long m_tex1;
    int m148;
    int m14C;
    unsigned short m150;
    unsigned short m152;
    unsigned short m154;
    unsigned short m156;
    short pad158;
    short m15A;
    char pad15C[0x40];
    Font_00172A28* m_next;
    int CharWidth(int c) const
    {
        Glyph_00172A28* g = &m_glyphs[m_map[c]];
        return (g->x1 - g->x0) >> 4;
    }
};

struct Tex_00172A28;

extern char* D_00394274;
extern int D_00393F5C;
extern Font_00172A28* D_00393F60;
extern Tex_00172A28 D_003E2798;

extern "C" void* func_00172980();
extern "C" void* func_0010BDE0(int size);
extern "C" int func_00110F68(void* buf, int a, int size, void* fh);
extern "C" int func_00110EF8(void* fh);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void func_001657F0(Tex_00172A28* t, int* w, int* h, int fmt);
extern "C" int func_00165890(Tex_00172A28* t, int w, int h, int fmt);
extern "C" void func_001644E8(int a, int b, int c, int d, int e, int f, int g);
extern "C" int func_00164808(int reg, unsigned long v);
extern "C" void func_001647B0(int reg, unsigned long v);

static inline unsigned long BitBlt(int dbp, int dbw, int dpsm)
{
    return ((unsigned long)(dbp & 0x3FFF) << 32) | ((unsigned long)(dbw & 0x3F) << 48) | ((unsigned long)dpsm << 56);
}

static inline unsigned long Tex0(int tbp, int tbw, int psm, int tw, int th, int tcc, int tfx, int cbp, int cpsm,
    int csm, int csa, int cld)
{
    return (unsigned long)(tbp & 0x3FFF) | ((unsigned long)(tbw & 0x3F) << 14) | ((unsigned long)psm << 20)
        | ((unsigned long)(tw & 0xF) << 26) | ((unsigned long)(th & 0xF) << 30) | ((unsigned long)tcc << 34)
        | ((unsigned long)tfx << 35) | ((unsigned long)(cbp & 0x3FFF) << 37) | ((unsigned long)cpsm << 51)
        | ((unsigned long)csm << 55) | ((unsigned long)csa << 56) | ((unsigned long)cld << 61);
}

extern "C" Font_00172A28* func_00172A28()
{
    char buf[0x800];
    char* savedPacket = D_00394274;
    void* fh = func_00172980();
    Font_00172A28* font = (Font_00172A28*)func_0010BDE0(0x1A0);
    int* hdr = (int*)buf;
    func_00110F68(buf, 1, 0x10, fh);
    int count = hdr[1];
    font->m0 = hdr[2] << 4;
    font->m4 = hdr[3] << 4;
    func_003315B8(font->m_map, 0, 0x100);
    func_003315B8(font->m_map2, 0, 0x20);
    font->m_glyphs = (Glyph_00172A28*)func_0010BDE0(count * 10);
    func_00110F68(buf, 1, count * 4, fh);
    {
        Entry_00172A28* e = (Entry_00172A28*)buf;
        Glyph_00172A28* g = font->m_glyphs;
        int i;
        for (i = 0; i < count; i++) {
            g->base = e->a << 4;
            short c = e->c;
            if (c >= 0)
                font->m_map[(unsigned char)c] = i;
            else
                font->m_map2[(unsigned char)~c] = i;
            g++;
            e++;
        }
    }
    if (font->m_default) {
        int i;
        for (i = 0; i < 0x100; i++) {
            if (!font->m_map[i] && i != 0x41 && i != 0x61)
                font->m_map[i] = font->m_default;
            if (i < 0x1F && !font->m_map2[i])
                font->m_map2[i] = font->m_default;
        }
    }
    func_00110F68(buf, 1, 0x10, fh);
    int width = ((unsigned short*)buf)[2];
    int height = ((unsigned short*)buf)[3];
    int pixels = width * height;
    int qwc = (pixels + 15) >> 4;
    int bytes = qwc << 4;
    int size = bytes + 0x4C0;
    font->m_size = size;
    font->m_data = func_0010BDE0(size);
    int tw = width;
    int th = height;
    D_00394274 = (char*)font->m_data;
    func_001657F0(&D_003E2798, &tw, &th, 0x13);
    font->m150 = func_00165890(&D_003E2798, tw, th, 0x13);
    unsigned int tbw = (width + 63) >> 6;
    font->m152 = 4;
    font->m154 = D_00393F5C + 4;
    font->m156 = D_00393F5C;
    if (tbw < 2)
        tbw = 2;
    func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
    font->m148 = func_00164808(0x50, ((unsigned long)(font->m154 & 0x3FFF) << 32) | ((unsigned long)(tbw & 0x3F) << 48) | ((unsigned long)0x13 << 56));
    func_001647B0(0x51, 0);
    func_001647B0(0x52, (unsigned long)(width & 0xFFF) | ((unsigned long)(height & 0xFFF) << 32));
    func_001647B0(0x53, 0);
    func_001644E8(0, 0, 2, 0, 0, 0, qwc);
    func_00110F68(D_00394274, 1, (pixels + 3) & 0xFFFFFFFC, fh);
    D_00394274 += bytes;
    func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
    font->m14C = func_00164808(0x50, ((unsigned long)(font->m156 & 0x3FFF) << 32) | ((unsigned long)1 << 48) | ((unsigned long)0 << 56));
    func_001647B0(0x51, 0);
    func_001647B0(0x52, (unsigned long)0x10 | ((unsigned long)0x10 << 32));
    func_001647B0(0x53, 0);
    func_001644E8(0, 0, 2, 0, 0, 0, 0x40);
    func_00110F68(D_00394274, 1, 0x400, fh);
    {
        int i;
        for (i = 0; i < 0x100; i += 0x20) {
            int k;
            for (k = 0; k < 8; k++) {
                int t = ((int*)D_00394274)[i + k + 8];
                ((int*)D_00394274)[i + k + 8] = ((int*)D_00394274)[i + k + 16];
                ((int*)D_00394274)[i + k + 16] = t;
            }
        }
    }
    D_00394274 += 0x400;
    func_00110F68(buf, 1, count * 8 | 4, fh);
    {
        unsigned short* e = (unsigned short*)(buf + 4);
        Glyph_00172A28* g = font->m_glyphs;
        int i;
        for (i = 0; i < count; i++) {
            int x = (e[0] << 4) + 8;
            g->x0 = x;
            int y = (e[1] << 4) + 8;
            g->y0 = y;
            g->x1 = x + (e[2] << 4);
            g->y1 = y + (e[3] << 4);
            e += 4;
            g++;
        }
    }
    int lw = 0;
    while ((1 << lw) < width)
        lw++;
    int lh = 0;
    while ((1 << lh) < height)
        lh++;
    font->m_tex0 = (unsigned long)(font->m154 & 0x3FFF) | ((unsigned long)(tbw & 0x3F) << 14) | ((unsigned long)0x13 << 20)
        | ((unsigned long)(lw & 0xF) << 26) | ((unsigned long)(lh & 0xF) << 30) | ((unsigned long)1 << 34)
        | ((unsigned long)0 << 35) | ((unsigned long)(font->m156 & 0x3FFF) << 37) | ((unsigned long)0 << 51)
        | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) | ((unsigned long)1 << 61);
    font->m_tex1 = 0x61;
    D_00393F5C += font->m150 + font->m152;
    font->m_next = D_00393F60;
    D_00393F60 = font;
    func_00110EF8(fh);
    D_00394274 = savedPacket;
    font->m15A = font->CharWidth(0x49);
    return font;
}
