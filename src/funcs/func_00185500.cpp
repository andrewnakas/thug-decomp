class Item_00185500 {
public:
    char pad0[0x10];
    Item_00185500* m_next;
    int m14;
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Stop();
};

extern "C" void func_00185238(void* emit);

class Emit_00185500 {
public:
    char pad0[0x100];
    Item_00185500* m_items;
    unsigned int m_flags;

    void StopAll();
};

void Emit_00185500::StopAll()
{
    for (Item_00185500* item = m_items; item; item = item->m_next) {
        item->Stop();
    }
    m_flags |= 0x20;
    func_00185238(this);
}
