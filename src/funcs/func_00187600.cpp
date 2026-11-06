struct Item_00187600 {
    char pad0[0x18];
    int m18;
};

class Obj_00187600 {
public:
    char pad0[0x24];
    int m24;
    int m_busy;
    virtual void V1();
    virtual void Add(Item_00187600* item);
    virtual void Clear();

    void Set(Item_00187600* item, int v);
};

void Obj_00187600::Set(Item_00187600* item, int v)
{
    m_busy = 1;
    m24 = v;
    Clear();
    item->m18 = v;
    Add(item);
    m_busy = 0;
}
