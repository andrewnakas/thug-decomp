class Item_00185128 {
public:
    char pad0[0x10];
    Item_00185128* m_next;
    int m14;
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void SetPause(bool on);
};

class Emit_00185128 {
public:
    char pad0[0x100];
    Item_00185128* m_items;
    int m_flags;

    bool IsPause()
    {
        if (m_flags & 4) {
            return true;
        }
        return false;
    }
    void SetPause(bool on);
};

void Emit_00185128::SetPause(bool on)
{
    if (on == IsPause()) {
        return;
    }
    if (on) {
        m_flags |= 4;
    } else {
        m_flags &= ~4;
    }
    for (Item_00185128* item = m_items; item; item = item->m_next) {
        item->SetPause(on);
    }
}
