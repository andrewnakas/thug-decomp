class Item_0011A188 {
public:
    int m0;
    int m4;
    int m8;
    int m_pri;
    int m10;
    virtual ~Item_0011A188();
    virtual int Handle(int a);
    virtual void V3();
    virtual int Event(unsigned int name, int a, int b);
};

struct Obj_0011A188 {
    char pad[0x3C];
    Item_0011A188* m_items[4];
    int m_count;
    void SendAll();
};

void Obj_0011A188::SendAll()
{
    for (int i = 0; i < m_count; i++) {
        m_items[i]->Event(0x5F495AE0, 0, 0);
    }
}
