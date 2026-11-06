struct Link_002461E8 {
    int m_id;
};

struct Item_002461E8 {
    char pad[0x30];
    Link_002461E8* m_30;
    unsigned int GetRoot();
};

extern "C" void* func_00240850();
extern "C" Item_002461E8* func_0023BAD8(void* owner, int id, int create);
extern "C" unsigned int func_00246258(Item_002461E8* item);

unsigned int Item_002461E8::GetRoot()
{
    void* owner = func_00240850();
    Item_002461E8* it = this;
    Link_002461E8* p;
    while ((p = it->m_30) && p->m_id) {
        it = func_0023BAD8(owner, p->m_id, 1);
    }
    return func_00246258(it);
}
