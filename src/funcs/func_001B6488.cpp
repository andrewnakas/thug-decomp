struct Base1B6488 {
    int m_pad[6];
    Base1B6488();
    virtual ~Base1B6488();
};

struct Item1B6488 {
    int m0;
    int m4;
    virtual ~Item1B6488();
};

struct Comp1B6488 : Base1B6488 {
    Item1B6488* m1C;
    Comp1B6488();
    virtual void Update();
    virtual ~Comp1B6488();
};

Comp1B6488::~Comp1B6488()
{
    if (m1C) {
        delete m1C;
        m1C = 0;
    }
}
