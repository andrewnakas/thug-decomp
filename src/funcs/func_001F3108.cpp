struct Item_001F3108 {
    int m0;
    int m4;
    int m8;
    int m_refs;
};
extern "C" Item_001F3108* func_001F3648(void* table, unsigned int* key, int a);

struct Obj_001F3108 {
    char pad[0x18];
    void* m_table;
    int m1C;
    int m20;
    int m24;
    void Release(unsigned int key);
};
extern "C" void func_001F2EA0(Obj_001F3108* self, Item_001F3108* it);
extern "C" void func_001F2E08(Obj_001F3108* self, Item_001F3108* it);

void Obj_001F3108::Release(unsigned int key)
{
Item_001F3108* it = func_001F3648(m_table, &key, 1); if (it) { if (--it->m_refs == 0) { if (m24) func_001F2EA0(this, it); else func_001F2E08(this, it); } }
}
