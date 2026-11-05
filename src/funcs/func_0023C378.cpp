struct Link_0023C378 {
    int m_id;
};

struct Item_0023C378 {
    char pad[0x30];
    Link_0023C378* m_30;
};

struct Mgr_0023C378 {
    void Select(int id);
};

extern "C" Item_0023C378* func_0023BAD8(Mgr_0023C378* self, int id, int create);
extern "C" void func_00244378(Item_0023C378* item, int a, int b);

void Mgr_0023C378::Select(int id)
{
    Item_0023C378* item = func_0023BAD8(this, id, 1);
    Link_0023C378* p;
    while ((p = item->m_30) && p->m_id) {
        item = func_0023BAD8(this, p->m_id, 1);
    }
    func_00244378(item, 1, 0);
}
