extern "C" void func_001DAF58(void* p);

struct Base1A3FC0 {
    int m_pad[6];
    Base1A3FC0();
    virtual ~Base1A3FC0();
};

struct Item1A3FC0 {
    int m_pad[3];
    virtual ~Item1A3FC0();
};

struct Comp1A3FC0 : Base1A3FC0 {
    Item1A3FC0* m1C;
    Comp1A3FC0();
    virtual void Update();
    virtual ~Comp1A3FC0();
};

Comp1A3FC0::~Comp1A3FC0()
{
    if (m1C) {
        func_001DAF58(m1C);
        if (m1C) {
            delete m1C;
        }
    }
}
