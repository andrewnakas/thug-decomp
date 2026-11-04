struct Item_001DAB78 {
    int m_pad[3];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual int GetKey();
};

struct Entry_001DAB78 {
    Item_001DAB78* m_item;
    int m_key;
};

struct Table_001DAB78 {
    int m_pad[8];
    Entry_001DAB78 m_entries[(0xFC0 - 0x20) / 8];
    int m_count;
    int m_FC4;
    int m_total;
    void Add(Item_001DAB78* item);
};

void Table_001DAB78::Add(Item_001DAB78* item)
{
    m_entries[m_count].m_key = item->GetKey();
    m_entries[m_count++].m_item = item;
    m_total++;
}
