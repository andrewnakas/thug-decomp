struct Glyph_00173178 {
    unsigned short m0;
    unsigned short m2;
    unsigned short m4;
    unsigned short m6;
    unsigned short m8;
};

struct Font_00173178 {
    unsigned int m_height;
    int m4;
    Glyph_00173178* m_glyphs;
    unsigned char m_map[256];
    unsigned char m_special[76];
    unsigned short m_spacing;
    unsigned short m_space;
};

extern Font_00173178* D_0038BDB8;
extern "C" int func_001045B0(const char* s);
extern "C" char func_00130BE8(const char* s);

extern "C" void func_00173178(Font_00173178* self, const char* s, float* w, float* h)
{
    unsigned short width = 0;
    short spacing = self->m_spacing << 4;
    short space = self->m_space << 4;
    for (;;) {
        Glyph_00173178* g = 0;
        Font_00173178* font = self;
        int esc = 0;
        while (*s == '\\' && !esc) {
            s++;
            if (*s == '\\') {
                break;
            }
            switch (*s) {
            case '\\':
                esc = 1;
                break;
            case 'C':
            case 'c':
                s += 2;
                break;
            case 'S':
            case 's':
                s++;
                g = &self->m_glyphs[self->m_special[func_001045B0(s)]];
                esc = 1;
                break;
            case 'B':
            case 'b':
                s++;
                {
                    int i = func_001045B0(s);
                    font = D_0038BDB8;
                    g = &font->m_glyphs[font->m_special[i]];
                }
                esc = 1;
                break;
            case 'M':
            case 'm': {
                char buf[2];
                s++;
                buf[0] = func_00130BE8(s);
                int i = func_001045B0(buf);
                font = D_0038BDB8;
                g = &font->m_glyphs[font->m_special[i]];
                esc = 1;
                break;
            }
            }
        }
        if (*s == 0) {
            break;
        }
        unsigned short adv;
        if (*s != ' ' || g) {
            if (!g) {
                g = &font->m_glyphs[font->m_map[(unsigned char)*s]];
            }
            adv = width + g->m4 - g->m0;
        } else {
            adv = width + space;
        }
        width = adv + spacing;
        s++;
    }
    *w = width * 0.0625f;
    *h = self->m_height * 0.0625f;
}
