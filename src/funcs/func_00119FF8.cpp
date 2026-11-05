class Item_00119FF8 {
public:
    int m0;
    int m4;
    int m8;
    int m_pri;
    int m10;
    virtual ~Item_00119FF8();
    virtual int Handle(int a);
};

struct Obj_00119FF8 {
    char pad[0x3C];
    Item_00119FF8* m_items[4];
    int m_count;
    int HandleAll(int a);
};

int Obj_00119FF8::HandleAll(int a)
{
    for (int i = 0; i < m_count; i++) {
        m_items[i]->Handle(a);
    }
    return 1;
}
