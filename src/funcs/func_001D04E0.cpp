struct Item_001D04E0 {
    int m0;
    int m_key;
    char m_pad8[0x20 - 8];
    virtual ~Item_001D04E0();
    virtual void V1();
    virtual void V2();
    virtual int Release();
};

extern "C" void func_001D1000(Item_001D04E0* item);
extern "C" void func_001D0EF8(void* table, int* key);

struct Obj_001D04E0 {
    char m_pad0[0xC];
    void* m_table;
    void Remove(Item_001D04E0* item);
};

void Obj_001D04E0::Remove(Item_001D04E0* item)
{
    int key = item->m_key;
    func_001D1000(item);
    item->Release();
    delete item;
    func_001D0EF8(m_table, &key);
}
