/* fuzzy: 49.2 */
/* Text draw: walks the string, handles the \C (colour), \S (special glyph), \B (button-font glyph) and \\ escapes,
   and emits one sprite (two UV/XY vertex pairs) per glyph into the VU1 batch, restarting the batch when the
   packet buffer fills up. */
struct Glyph_001735F8 {
    unsigned short m_u0;
    unsigned short m_v0;
    unsigned short m_u1;
    unsigned short m_v1;
    unsigned short m_base;
};

struct Font_001735F8 {
    unsigned int m_height;
    unsigned int m_ascent;
    Glyph_001735F8* m_glyphs;
    unsigned char m_map[256];
    unsigned char m_special[76];
    short m_spacing;
    short m_space;
    unsigned int m_colors[1];
};

class Batch_001735F8 {
public:
    int m0;
    int m_clip;
    int m8;
    unsigned int m_color;
    unsigned long* m_xyoffset;
    int m14;
    virtual void V0();
    virtual void V1();
    virtual void Begin();
    virtual void V3();
    virtual void End();
};

class Text_001735F8 : public Batch_001735F8 {
public:
    Font_001735F8* m_font;
    const char* m_text;
    float m_x;
    float m_y;
    float m_scaleX;
    float m_scaleY;
    unsigned int m_rgba;
    int m_lockColor;
    void Draw();
};

extern float D_0038C0FC;
extern float D_0038C100;
extern int D_0038C104;
extern unsigned int D_0038C108;
extern int D_0038882C;
extern Font_001735F8* D_0038BDB8;
extern Font_001735F8* D_0038BDC0;
extern unsigned char* D_00394274;
extern unsigned char* D_003942E4;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_00360D70[];
extern char D_310[];
extern char D_4C0[];

extern "C" int func_001045B0(const char* s);
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a);
extern "C" void func_00164490(int a);
extern "C" void func_00164408(int a, int b, int c, int d, int e, unsigned int f);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void PutQ(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    ((unsigned int*)D_00394274)[0] = a;
    ((unsigned int*)D_00394274)[1] = b;
    ((unsigned int*)D_00394274)[2] = c;
    ((unsigned int*)D_00394274)[3] = d;
    D_00394274 += 0x10;
}

void Text_001735F8::Draw()
{
    float sx = D_0038C0FC;
    int x = ((int)(m_x * sx * 16.0f) + (D_0038882C != 1 ? 0x7000 : 0x6C00)) + ((*m_xyoffset & 0x7FF) << 4);
    int y0 = ((int)(m_y * D_0038C100 * 16.0f) + (D_0038882C != 1 ? 0x7000 : 0x7200)) +
             (((*m_xyoffset >> 32) & 0x7FF) << 4);
    unsigned int color = D_0038C104 ? D_0038C108 : m_color;
    Font_001735F8* f = m_font;
    float spacing = (float)(f->m_spacing << 4) * m_scaleX * sx;
    float space = (float)(f->m_space << 4) * m_scaleX * sx;
    const char* s = m_text;

    for (;;) {
        Font_001735F8* font = m_font;
        Glyph_001735F8* g = 0;
        int esc = 0;
        while (*s == '\\' && !esc) {
            s++;
            char c = *s;
            if (c == '\\') {
                esc = 1;
            } else if (c == 'C' || c == 'c') {
                s++;
                int i = func_001045B0(s);
                s++;
                unsigned int saved = m_rgba;
                if (i && !m_lockColor)
                    m_rgba = m_font->m_colors[i - 1];
                End();
                Begin();
                m_rgba = saved;
            } else if (c == 'S' || c == 's') {
                s++;
                esc = 1;
                g = &m_font->m_glyphs[m_font->m_special[func_001045B0(s)]];
            } else if (c == 'B' || c == 'b') {
                s++;
                esc = 1;
                int i = func_001045B0(s);
                font = D_0038BDB8;
                g = &font->m_glyphs[font->m_special[i]];
                D_0038BDC0 = font;
                End();
                Begin();
                D_0038BDC0 = 0;
            }
        }
        if (*s == 0)
            return;
        if (*s == ' ' && !g) {
            x += (int)(space + spacing);
            s++;
            continue;
        }
        if (!g)
            g = &font->m_glyphs[font->m_map[(unsigned char)*s]];
        float top = (float)(font->m_ascent - g->m_base);
        int u0 = g->m_u0;
        int v0 = g->m_v0;
        int u1 = g->m_u1;
        int v1 = g->m_v1;
        int ya = y0 + (int)(top * m_scaleY * D_0038C100);
        int yb = ya + (int)((float)(v1 - v0) * m_scaleY * D_0038C100);
        int xb = x + (int)((float)(u1 - u0) * m_scaleX * D_0038C0FC);
        if (!m_clip || !((x | xb | y0 | yb) & 0xFFFF0000)) {
            PutQ(u0, v0, 0, 0);
            PutQ(x, ya, color, 0);
            PutQ(u1, v1, 0, 0);
            PutQ(xb, yb, color, 0);
        }
        x = xb + (int)spacing;
        s++;

        if ((D_00394274 - D_003942E4) >> 4 >= 0xFA) {
            unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
            D_00394290 = ((D_00394274 - D_00394288) - 4) * 8 / (D_0039428C * D_00394284);
            while (D_00394274 < end)
                *D_00394274++ = 0;
            if (D_00394290 == 0) {
                D_00394274 -= 4;
            } else if (D_00394290 < 0x100) {
                D_00394288[2] = D_00394290;
            } else if (D_00394290 == 0x100) {
                D_00394288[2] = 0;
            } else {
                func_00103F28(D_00360D70);
                func_00334148(1);
            }
            func_00164490(1);
            Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
            D_00394294 = D_00394280;
            Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C014000);
            D_00394290 = 1;
            func_00164408(0x53, 2, 0, 0x156, 1, (unsigned int)D_4C0 >> 3);
            D_00394284 = 0x20;
            D_00394288 = D_00394274;
            D_0039428C = 4;
            Put((((unsigned short)D_00394280 + 1) & 0x3FF) | 0x6C000000);
        }
        if (font != m_font) {
            End();
            Begin();
        }
    }
}
