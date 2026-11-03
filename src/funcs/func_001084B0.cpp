struct Heap_001084B0 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_001084B0* D_00388A70;
extern "C" void* func_0010A638(Heap_001084B0*, int, int, int);
extern "C" void* func_00109B78(void*, const char*, int);
extern "C" void func_00108028(const char*, char*, int);
extern "C" void* func_00331404(void*, const void*, unsigned int);
extern "C" char* func_0010BDE0(int);
extern "C" void func_0010BFC0(const char*);
extern "C" void func_0010BFC8();

struct Item_001084B0 {
    int m_packed;
    char* m_data;
    char* m_unpacked;
    unsigned int m_pos;
    unsigned int m_size;
};

struct Archive_001084B0 {
    int m0;
    void* m_header;
    int m_count;
    void* m_table;
    Item_001084B0* m_cur;
    int m_14;
    int m_18;
    Item_001084B0* Open(const char* name);
    char* Load(const char* name, int* size, char* buf);
    unsigned int Read(char* dst, unsigned int n);
};

char* Archive_001084B0::Load(const char* name, int* size, char* buf)
{
    Item_001084B0* item = (Item_001084B0*)func_00109B78(m_table, name, 0);
    if (!item)
        return 0;
    *size = item->m_size;
    if (!buf)
        buf = func_0010BDE0(item->m_size);
    if (!item->m_unpacked) {
        if (item->m_packed)
            func_00108028(item->m_data, buf, item->m_packed);
        else
            func_00331404(buf, item->m_data, item->m_size);
    } else {
        func_00331404(buf, item->m_unpacked, item->m_size);
    }
    return buf;
}
