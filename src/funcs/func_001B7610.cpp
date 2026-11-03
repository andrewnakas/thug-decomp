struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Part2683A0 {
    ~Part2683A0();
};

struct Comp1B7610 : Base184DD8 {
    Part2683A0* m1C;
    Comp1B7610();
    virtual void Update();
    virtual ~Comp1B7610();
};

Comp1B7610::~Comp1B7610()
{
    delete m1C;
}
