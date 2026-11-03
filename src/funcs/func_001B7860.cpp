struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Part26B498 {
    ~Part26B498();
};

struct Comp1B7860 : Base184DD8 {
    Part26B498* m1C;
    Comp1B7860();
    virtual void Update();
    virtual ~Comp1B7860();
};

Comp1B7860::~Comp1B7860()
{
    delete m1C;
}
