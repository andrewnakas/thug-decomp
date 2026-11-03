struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Part11D730 {
    ~Part11D730();
};

struct Comp19EAA8 : Base184DD8 {
    Part11D730* m1C;
    Comp19EAA8();
    virtual void Update();
    virtual ~Comp19EAA8();
};

Comp19EAA8::~Comp19EAA8()
{
    delete m1C;
}
