struct Link_00246338 {
    int m_id;
    Link_00246338* m_next;
    int m_8;
};

struct Base_00246338 {
    char pad[0x14];
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
    virtual int V17();
};

struct Item_00246338 : Base_00246338 {
    char pad18[0x2C - 0x18];
    Link_00246338* m_2C;
    bool Check();
};

bool Item_00246338::Check()
{
    if (V17()) {
        return true;
    }
    for (Link_00246338* l = m_2C; l; l = l->m_next) {
        if (l->m_8) {
            return true;
        }
    }
    return false;
}
