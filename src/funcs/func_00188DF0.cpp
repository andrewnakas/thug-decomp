extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0018A758(void* p, int bits);
extern "C" void* func_001E55B8(unsigned int id, int flag);
extern "C" char* func_001E91C0(void* array, int i);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_0018A800(void* table, unsigned int* key, void* value);

struct A_00188DF0 {
    char pad[0xC];
    int m_size;
};

struct E_00188DF0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m_type;
    int m_depth;
};

struct C_00188DF0 {
    E_00188DF0 m_entries[1024];
    int m_index;
    int m_wrapped;
    char m_names[256][0x40];
    void* m_table;
    int m_depth;
    int m_count;
    void Add(int a, int b, int c, int d, int e, int type);
};

void C_00188DF0::Add(int a, int b, int c, int d, int e, int type)
{
    if (!m_table) {
        m_table = func_0018A758(func_0010A638(D_00388A70, 0x18, 1, 0), 8);
        A_00188DF0* names = (A_00188DF0*)func_001E55B8(0x08114F90, 1);
        for (int i = 0; i < names->m_size; i++) {
            func_00331A9C(m_names[i], func_001E91C0(names, i));
            unsigned int key = func_001F0D78(func_001E91C0(names, i));
            func_0018A800(m_table, &key, m_names[i]);
        }
    }
    int prev = m_index - 1;
    if (prev < 0) prev = 0x3FF;
    if (type == 3 && m_entries[prev].m_type == type) {
        m_entries[prev].m0++;
        return;
    }
    if (type == 1) m_depth--;
    E_00188DF0* en = &m_entries[m_index];
    if (type == 3) en->m0 = 0;
    else en->m0 = a;
    en->m4 = b;
    en->m8 = c;
    en->mC = d;
    en->m_type = type;
    en->m10 = e;
    en->m_depth = m_depth;
    if (++m_index == 0x400) {
        m_index = 0;
        m_wrapped = 1;
    }
    if (type == 0) m_depth++;
    m_count++;
}
