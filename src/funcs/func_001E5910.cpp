struct Entry_001E5910 {
    int m_name;
    int m_value;
};

struct Sym_001E5910 {
    short m0;
    unsigned char m_type;
    char m3;
    int m4;
    int m8;
    int m_value;
};

extern "C" void* func_00105520(int name);
extern "C" void func_001E60C8(void* s, int name);
extern "C" Sym_001E5910* func_001E5188(void* s);

extern "C" void func_001E5910(Entry_001E5910* e, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        void* s = func_00105520(e[i].m_name);
        func_001E60C8(s, e[i].m_name);
        Sym_001E5910* sym = func_001E5188(s);
        sym->m_type = 8;
        sym->m_value = e[i].m_value;
    }
}
