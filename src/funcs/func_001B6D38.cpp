struct Base1B6D38 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1B6D38();
    virtual ~Base1B6D38();
};

struct Comp1B6D38 : Base1B6D38 {
    void* m1C[2];
    Comp1B6D38();
    virtual void Update();
    virtual ~Comp1B6D38();
};

Comp1B6D38::Comp1B6D38()
{
    m_type = 0xF27A294D;
    for (int i = 1; i >= 0; i--) {
        m1C[i] = 0;
    }
}
