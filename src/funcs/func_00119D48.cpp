class Item_00119D48 {
public:
    int m0;
    int m4;
    int m8;
    int m_pri;
    int m10;
    virtual ~Item_00119D48();
    virtual int Handle(int a);
};

struct Obj_00119D48 {
    char pad[0x3C];
    Item_00119D48* m_items[4];
    int m_count;
    void DeleteAll();
};

void Obj_00119D48::DeleteAll()
{
    for (int i = 0; i < m_count; i++) {
        delete m_items[i];
        m_items[i] = 0;
    }
    m_count = 0;
}
