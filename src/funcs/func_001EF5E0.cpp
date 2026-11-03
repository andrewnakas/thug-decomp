struct Obj_001EF5E0 {
    char m_pad[0x10];
    unsigned char* m_pc;
    void If();
};

extern "C" bool func_001EF228(Obj_001EF5E0* self);
extern "C" unsigned char* func_001EB070(unsigned char* p);

void Obj_001EF5E0::If()
{
    unsigned char* p = m_pc;
    m_pc = p + 1;
    bool negate = false;
    if (p[1] == 0x39) {
        negate = true;
        m_pc = p + 2;
    }
    bool result = func_001EF228(this);
    if (!m_pc) {
        return;
    }
    if (negate) {
        result = !result;
    }
    if (result) {
        return;
    }
    int depth = 0;
    if (*m_pc != 0x26 && *m_pc != 0x28) {
        do {
            unsigned char c = *m_pc;
            if (c == 0x25) {
                depth++;
            } else if (c == 0x28) {
                depth--;
            }
            m_pc = func_001EB070(m_pc);
        } while (depth || (*m_pc != 0x26 && *m_pc != 0x28));
    }
    m_pc++;
}
