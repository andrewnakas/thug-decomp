extern void* D_0038C7B0;

struct Link_00187588 {
    int m0;
    void* m_owner;
    int m8;
    Link_00187588* m_prev;
    Link_00187588* m_next;

    bool IsLinked() { return m_next != this; }
    void Unlink()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

struct Item_00187588 {
    char pad0[0x10];
    int m10;
    char pad14[0x18];
    Link_00187588 m_link;
};

extern "C" void func_00189278(void* mgr, Item_00187588* item, int a, int b);

class Obj_00187588 {
public:
    char pad0[0x20];
    unsigned int m20;
    int m24;
    int m28;

    void Remove(Item_00187588* item);
};

void Obj_00187588::Remove(Item_00187588* item)
{
    func_00189278(D_0038C7B0, item, m24, m28);
    if (item->m_link.IsLinked()) {
        item->m_link.Unlink();
        item->m10 = 0;
        m20 = 0xFFFFFFFF;
    }
}
