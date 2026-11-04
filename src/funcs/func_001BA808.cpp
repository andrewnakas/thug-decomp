struct Base1BA808 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1BA808();
    virtual ~Base1BA808();
};

struct Slot1BA808 {
    void* p;
    int m4;
    int m8;
};

struct Comp1BA808 : Base1BA808 {
    int m1C;
    Slot1BA808 m20[2];
    void* m38;
    Comp1BA808();
    virtual void Update();
    virtual ~Comp1BA808();
};

Comp1BA808::Comp1BA808()
{
    m_type = 0x404EB936;
    m1C = 0;
    int n = 2;
    while (n--) {
        m20[n].p = 0;
    }
}
