struct Heap_001083D8 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_001083D8* D_00388A70;
extern "C" void* func_0010A638(Heap_001083D8*, int, int, int);
extern "C" void* func_00109B78(void*, const char*, int);
extern "C" void func_00108028(const char*, char*, int);
extern "C" void* func_00331404(void*, const void*, unsigned int);
extern "C" char* func_0010BDE0(int);
extern "C" void func_0010BFC0(const char*);
extern "C" void func_0010BFC8();

struct Item_001083D8 {
    int m_packed;
    char* m_data;
    char* m_unpacked;
    unsigned int m_pos;
    unsigned int m_size;
};

struct Archive_001083D8 {
    int m0;
    void* m_header;
    int m_count;
    void* m_table;
    Item_001083D8* m_cur;
    int m_14;
    int m_18;
    Item_001083D8* Open(const char* name);
    char* Load(const char* name, int* size, char* buf);
    unsigned int Read(char* dst, unsigned int n);
};

extern "C" void func_00108560(Archive_001083D8*, Item_001083D8*);

Item_001083D8* Archive_001083D8::Open(const char* name)
{
    Item_001083D8* item = (Item_001083D8*)func_00109B78(m_table, name, 0);
    if (!item)
        return 0;
    func_00108560(this, item);
    if (!m_cur->m_unpacked && m_cur->m_packed) {
        func_0010BFC0(name);
        Item_001083D8* cur;
        if (m_18) {
            cur = m_cur;
            cur->m_unpacked = (char*)func_0010A638(D_00388A70, cur->m_size, 1, D_00388A70->m_DC);
        } else {
            cur = m_cur;
            cur->m_unpacked = (char*)func_0010A638(D_00388A70, cur->m_size, 1, D_00388A70->m_D8);
        }
        func_0010BFC8();
        func_00108028(m_cur->m_data, m_cur->m_unpacked, m_cur->m_packed);
    }
    return item;
}
