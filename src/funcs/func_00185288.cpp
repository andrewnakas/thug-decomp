extern void* D_0038C608;

struct Item_00185288 {
    char pad0[0xC];
    void* m_owner;
    Item_00185288* m_next;
};

extern "C" void func_001872C8(void* mgr, Item_00185288* item);

class Emit_00185288 {
public:
    char pad0[0x100];
    Item_00185288* m_items;

    void AddItem(Item_00185288* item);
};

void Emit_00185288::AddItem(Item_00185288* item)
{
    if (!m_items) {
        m_items = item;
    } else {
        Item_00185288* p = m_items;
        while (p->m_next) {
            p = p->m_next;
        }
        p->m_next = item;
    }
    item->m_owner = this;
    func_001872C8(D_0038C608, item);
}
