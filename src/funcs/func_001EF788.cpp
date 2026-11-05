struct Parser_001EF788 {
    char pad[0x10];
    unsigned char* m_cur;
};

extern "C" unsigned char* func_001EB070(unsigned char* p);

extern "C" void func_001EF788(Parser_001EF788* p)
{
    while (*p->m_cur != '=') {
        if (*p->m_cur == '<') {
            p->m_cur++;
            func_001EF788(p);
        } else {
            p->m_cur = func_001EB070(p->m_cur);
        }
    }
    p->m_cur++;
}
