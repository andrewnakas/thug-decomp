struct Heap_001262A0 {
    char pad[0xE4];
    int mE4;
};

extern Heap_001262A0* D_00388A70;
extern "C" int func_00331BB8(const char* s);
extern "C" void func_0010A8D8(Heap_001262A0* heap, void* p);
extern "C" void func_0010A950(Heap_001262A0* heap, int ctx);
extern "C" char* func_0010A638(Heap_001262A0* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_001262A0* heap);
extern "C" char func_00130BE8(const char* s);
extern "C" void func_00135890(void* font, const char* text, float* w, float* h);

struct C_001262A0 {
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x1A0 - 0x10];
    char* m_text;
    int m1A4;
    void* m_font;
    void SetText(const char* text);
};

extern "C" void func_00123C40(C_001262A0* self, float a, float b, int f);

void C_001262A0::SetText(const char* text)
{
    int len = func_00331BB8(text);
    int size = len + 1;
    if (!m_text || func_00331BB8(m_text) < len) {
        if (m_text)
            func_0010A8D8(D_00388A70, m_text);
        func_0010A950(D_00388A70, D_00388A70->mE4);
        m_text = func_0010A638(D_00388A70, size, 1, 0);
        func_0010A9B0(D_00388A70);
    }
    const char* p = text;
    char* d = m_text;
    while (*p) {
        if (*p == '\\') {
            char n = p[1];
            if (n == *p) {
                *d = *p;
                p++;
                d++;
            } else if (n == '_') {
                *d++ = ' ';
                p += 2;
                continue;
            } else if (n == 'm') {
                *d = *p;
                p += 2;
                d++;
                *d = 'b';
                d++;
                *d++ = func_00130BE8(p++);
                continue;
            }
        }
        *d++ = *p++;
    }
    *d = 0;
    if (m_font) {
        float w;
        float h;
        func_00135890(m_font, m_text, &w, &h);
        if (!(m_flags & 0x2000))
            func_00123C40(this, w, h, 0);
    }
    m_flags |= 0x1000;
}
