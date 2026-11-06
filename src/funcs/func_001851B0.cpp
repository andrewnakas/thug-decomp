class Item_001851B0 {
public:
    char pad0[0x10];
    Item_001851B0* m_next;
    int m14;
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void SetHide(bool on);
};

class Emit_001851B0 {
public:
    char pad0[0x100];
    Item_001851B0* m_items;
    int m_flags;

    bool IsHide()
    {
        if (m_flags & 2) {
            return true;
        }
        return false;
    }
    void SetHide(bool on);
};

void Emit_001851B0::SetHide(bool on)
{
    if (on == IsHide()) {
        return;
    }
    if (on) {
        m_flags |= 2;
    } else {
        m_flags &= ~2;
    }
    for (Item_001851B0* item = m_items; item; item = item->m_next) {
        item->SetHide(on);
    }
}
