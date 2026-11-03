struct Heap_0010D190;
extern Heap_0010D190* D_00388A70;
extern "C" void* func_0010A638(Heap_0010D190*, int, int, int);
extern "C" void* func_00331A9C(char*, const char*);

struct Name8_0010D190 {
    char c[8];
};

extern char D_00388C00[];

struct Pool_0010D190 {
    char* m_buffer;
    char* m_end;
    int m_count;
    int m_elemSize;
    int m_used;
    char* m_free;
    char m_name[0x40];
    int m_58;
    Pool_0010D190(int elemSize, int count, const char* name);
};

Pool_0010D190::Pool_0010D190(int elemSize, int count, const char* name)
{
    m_count = count;
    m_elemSize = elemSize;
    char* buf = (char*)func_0010A638(D_00388A70, count * elemSize, 1, 0);
    m_buffer = buf;
    m_used = 0;
    m_58 = 0;
    m_free = buf;
    m_end = buf + m_count * m_elemSize;
    char* p = buf;
    for (int i = 0; i < m_count; i++) {
        if (i < m_count - 1)
            *(char**)p = p + m_elemSize;
        else
            *(char**)p = 0;
        p += m_elemSize;
    }
    if (name)
        func_00331A9C(m_name, name);
    else
        *(Name8_0010D190*)m_name = *(Name8_0010D190*)D_00388C00;
}
