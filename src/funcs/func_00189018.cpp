extern char D_00361D00[];
extern char D_00361D40[];
extern char D_00361D68[];
extern "C" int func_00103F28(char* fmt, ...);

struct E_00189018 {
    int m[7];
};

struct C_00189018 {
    E_00189018 m_entries[1024];
    int m_index;
    int m_wrapped;
    char m_names[256][0x40];
    void* m_table;
    int m_depth;
    int m_count;
    void Dump(int all, int last);
    void PrintEntry(int i);
};

void C_00189018::Dump(int all, int last)
{
    int i = 0;
    int n = m_index;
    if (m_wrapped) {
        i = n;
        n = 0x400;
    }
    if (all) last = m_count;
    func_00103F28(D_00361D00);
    if (all) func_00103F28(D_00361D40);
    else func_00103F28(D_00361D68);
    for (; n > 0; n--) {
        if (n <= last) PrintEntry(i);
        i++;
        if (i == 0x400) i = 0;
    }
    func_00103F28(D_00361D00);
    m_count = 0;
}
