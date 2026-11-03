struct Heap_001F2F88 {
    char m_pad[0xEC];
    int m_EC;
};

struct Data_001F2F88 {
    int m_0;
    unsigned int m_size;
    unsigned int m_packed;
    char m_data[1];
};

struct Entry_001F2F88 {
    int m_0;
    int m_name;
    int m_8;
    Data_001F2F88* m_C;
};

struct Node_001F2F88 {
    int m_0;
    int m_name;
    char* m_buf;
    int m_refs;
};

struct Mgr_001F2F88 {
    char m_pad[0x18];
    void* m_18;
    char* Get(int name);
};

extern Heap_001F2F88* D_00388A70;
extern "C" Entry_001F2F88* func_001E5040(int name);
extern "C" Node_001F2F88* func_001F3648(void* table, int* key, int a);
extern "C" void func_001F2E40(Mgr_001F2F88* self, Node_001F2F88* n);
extern "C" void func_001F2EF8(Mgr_001F2F88* self, unsigned int size, int key);
extern "C" void* func_001F36B0(int size);
extern "C" Node_001F2F88* func_001F2C68(void* mem);
extern "C" void func_0010A950(void* heap, int a);
extern "C" char* func_0010BDE0(unsigned int size);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_00105F10(char* src, char* dst, unsigned int size);
extern "C" void func_001EC580(char* buf);
extern "C" void func_001F3700(void* table, int* key, Node_001F2F88* n);

char* Mgr_001F2F88::Get(int name)
{
    int key = name;
    Entry_001F2F88* e = func_001E5040(name);
    if (e) {
        key = e->m_name;
    }
    Node_001F2F88* n = func_001F3648(m_18, &key, 1);
    if (n) {
        n->m_refs++;
        func_001F2E40(this, n);
        return n->m_buf;
    }
    if (e) {
        unsigned int size = e->m_C->m_size;
        unsigned int packed = e->m_C->m_packed;
        func_001F2EF8(this, size, key);
        Node_001F2F88* nn = func_001F2C68(func_001F36B0(0x18));
        func_0010A950(D_00388A70, D_00388A70->m_EC);
        char* buf = func_0010BDE0(size);
        func_0010A9B0(D_00388A70);
        if (packed < size) {
            func_00105F10(e->m_C->m_data, buf, packed);
        } else {
            char* src = e->m_C->m_data;
            char* dst = buf;
            for (unsigned int i = 0; i < size; i++) {
                *dst++ = *src++;
            }
        }
        func_001EC580(buf);
        nn->m_buf = buf;
        nn->m_refs = 1;
        nn->m_name = key;
        func_001F3700(m_18, &key, nn);
        return nn->m_buf;
    }
    return 0;
}
