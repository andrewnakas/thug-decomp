struct C_001AF538 {
    int m_pad[1223];
    int m131C;
    int m1320[10];
    unsigned int m1348[10];
    int m1370;
    unsigned int m1374;
    void Mark(const char* name);
};

extern "C" unsigned int func_001AF480(C_001AF538* self, int id, const char* name);

void C_001AF538::Mark(const char* name)
{
    for (int i = 0; i < m131C; i++) {
        m1348[i] |= func_001AF480(this, m1320[i], name);
    }
    if (m1370) m1374 |= func_001AF480(this, m1370, name);
}
