struct Heap_001085F0 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_001085F0* D_00388A70;
extern "C" void* func_0010A638(Heap_001085F0*, int, int, int);
extern "C" void* func_00109B78(void*, const char*, int);
extern "C" void func_00108028(const char*, char*, int);
extern "C" void* func_00331404(void*, const void*, unsigned int);
extern "C" char* func_0010BDE0(int);
extern "C" void func_0010BFC0(const char*);
extern "C" void func_0010BFC8();

struct Item_001085F0 {
    int m_packed;
    char* m_data;
    char* m_unpacked;
    unsigned int m_pos;
    unsigned int m_size;
};

struct Archive_001085F0 {
    int m0;
    void* m_header;
    int m_count;
    void* m_table;
    Item_001085F0* m_cur;
    int m_14;
    int m_18;
    Item_001085F0* Open(const char* name);
    char* Load(const char* name, int* size, char* buf);
    unsigned int Read(char* dst, unsigned int n);
};

unsigned int Archive_001085F0::Read(char* dst, unsigned int n)
{
    unsigned int count = n;
    Item_001085F0* cur = m_cur;
    unsigned int pos = cur->m_pos;
    unsigned int rem = cur->m_size - pos;
    if (rem < count)
        count = rem;
    if (cur->m_packed)
        func_00331404(dst, cur->m_unpacked + pos, count);
    else
        func_00331404(dst, cur->m_data + pos, count);
    m_cur->m_pos += count;
    return count;
}
