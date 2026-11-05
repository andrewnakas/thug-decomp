class Item_00119CB0 {
public:
    int m0;
    int m4;
    int m8;
    int m_pri;
    int m10;
    virtual ~Item_00119CB0();
    virtual int Handle(int a);
};

struct Obj_00119CB0 {
    char pad[0x3C];
    Item_00119CB0* m_items[4];
    int m_count;
    void Insert(Item_00119CB0* item, int pri);
};

void Obj_00119CB0::Insert(Item_00119CB0* item, int pri)
{
    int i;
    for (i = 0; i < m_count; i++) {
        if (m_items[i]->m_pri < pri) {
            for (int j = m_count; j > i; j--) {
                m_items[j] = m_items[j - 1];
            }
            break;
        }
    }
    m_items[i] = item;
    m_count++;
}
