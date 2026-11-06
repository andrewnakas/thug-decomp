struct Item_001F3180 {
    int m0;
    int m4;
    int m8;
    int m_refs;
};
extern "C" Item_001F3180* func_001F3648(void* table, unsigned int* key, int a);

struct Obj_001F3180 {
    char pad[0x18];
    void* m_table;
    void Reload(unsigned int key);
};
extern "C" void func_001F2EA0(Obj_001F3180* self, Item_001F3180* it);
extern "C" void func_001F2F88(Obj_001F3180* self, unsigned int key);

void Obj_001F3180::Reload(unsigned int key)
{
    Item_001F3180* it = func_001F3648(m_table, &key, 1);
    if (it) {
        int refs = it->m_refs;
        func_001F2EA0(this, it);
        func_001F2F88(this, key);
        func_001F3648(m_table, &key, 1)->m_refs = refs;
    }
}
