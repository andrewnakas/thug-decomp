struct Heap_001081A8 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

extern Heap_001081A8* D_00388A70;
extern "C" void* func_0010A638(Heap_001081A8*, int, int, int);
extern "C" void func_0010A8D8(Heap_001081A8*, void*);
extern "C" void* func_00109AE8(void*, int);
extern "C" int func_00109B78(void*, void*, int);
extern "C" void func_00109C78(void*, void*, void*);

struct Entry_001081A8 {
    int m_size;
    int m_packed;
    short m_nameLen;
    short pad;
    int padC;
    char m_key[1];
};

struct Item_001081A8 {
    int m_packed;
    char* m_data;
    int m8;
    int mC;
    int m_size;
};

struct Archive_001081A8 {
    int m0;
    void* m_header;
    int m_count;
    void* m_table;
    int m_10;
    int m_14;
    int m_18;
    Archive_001081A8* Init(char* header, int flag);
};

Archive_001081A8* Archive_001081A8::Init(char* header, int flag)
{
    m_18 = flag;
    m_table = func_00109AE8(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    m_header = header;
    m_count = *(int*)(header + 8);
    Entry_001081A8* e = (Entry_001081A8*)(header + 0xC);
    for (int i = 0; i < m_count; i++) {
        int size = e->m_size;
        char* key = e->m_key;
        int nameLen = e->m_nameLen;
        int packed = e->m_packed;
        int stored = size;
        char* data = (char*)e + (nameLen + 0x10);
        if (packed)
            stored = packed;
        Item_001081A8* item;
        if (m_18)
            item = (Item_001081A8*)func_0010A638(D_00388A70, 0x14, 1, D_00388A70->m_DC);
        else
            item = (Item_001081A8*)func_0010A638(D_00388A70, 0x14, 1, D_00388A70->m_D8);
        if (!func_00109B78(m_table, key, 1)) {
            func_00109C78(m_table, key, item);
            item->m_size = size;
            item->m_packed = packed;
            item->m_data = data;
            item->mC = 0;
            item->m8 = 0;
        } else {
            func_0010A8D8(D_00388A70, item);
        }
        e = (Entry_001081A8*)((char*)e + ((nameLen + 0x10) + ((stored + 3) & ~3)));
    }
    m_10 = 0;
    m_14 = 0;
    return this;
}
