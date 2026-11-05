extern "C" unsigned char* func_001EB070(unsigned char* p);

struct Parser_001EF6E0 {
    char pad0[0x10];
    unsigned char* m_p;
    void SkipParens();
};

void Parser_001EF6E0::SkipParens()
{
    int depth = 0;
    if (*m_p != '(') {
        do {
            unsigned char c = *m_p;
            if (c == '%') {
                depth++;
            } else if (c == '(') {
                depth--;
            }
            m_p = func_001EB070(m_p);
        } while (depth || *m_p != '(');
    }
    m_p++;
}
