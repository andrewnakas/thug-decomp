extern "C" void func_001D1000(void* n);
extern "C" void func_001D0EF8(void* tbl, int* key);

struct Item_001D0460 {
    int m0;
    int m_key;
    char pad8[0x18];
    virtual ~Item_001D0460();
};

struct Holder_001D0460 {
    char pad0[0x14];
    Item_001D0460* m_14;
};

struct Mgr_001D0460 {
    char pad0[0xC];
    void* m_C;
    void Clear(Holder_001D0460* h);
};

void Mgr_001D0460::Clear(Holder_001D0460* h)
{
    while (h->m_14) {
        int key = h->m_14->m_key;
        func_001D1000(h->m_14);
        delete h->m_14;
        func_001D0EF8(m_C, &key);
    }
}
