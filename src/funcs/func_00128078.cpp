struct C_00128078 {
    char pad0[0x188];
    float m188;
    char pad18C[0x1A0 - 0x18C];
    void* m1A0;
    char** m_lines;
    int m_numLines;
    int m_curLine;
    int m_lineLen;
    float m_lineWidth;
    int m_maxLines;
    char pad1BC[0x1C4 - 0x1BC];
    float m_scale;
    void AddText(const char* text);
};

extern "C" void* func_00130B80(void* o);
extern "C" int func_00127F98(C_00128078* self, char* word, const char** p);
extern "C" void func_00135890(void* font, const char* text, float* w, float* h);
extern "C" unsigned int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* d, const char* s);

void C_00128078::AddText(const char* text)
{
    int last = 0;
    void* font = func_00130B80(m1A0);
    const char* p = text;
    int r;
    do {
        char word[0x60];
        r = func_00127F98(this, word, &p);
        float w;
        float h;
        func_00135890(font, word, &w, &h);
        w *= m_scale;
        if ((m_lineWidth > 0.0f && m_lineWidth + w > m188) || last == 1
            || m_lineLen + func_00331BB8(word) >= 0x60) {
            char* line = m_lines[m_curLine];
            if (line[m_lineLen - 1] == ' ')
                line[m_lineLen - 1] = 0;
            m_numLines++;
            m_curLine++;
            if (m_curLine >= m_maxLines)
                m_curLine = 0;
            m_lineLen = 0;
            m_lineWidth = 0.0f;
        }
        last = r;
        func_00331A9C(m_lines[m_curLine] + m_lineLen, word);
        m_lineLen += func_00331BB8(word);
        m_lineWidth += w;
    } while (last != 2);
}
