struct Base137A60 {
    int m_pad[6];
    Base137A60();
    virtual ~Base137A60();
};

struct Part16C510 {
    ~Part16C510();
};

struct Comp14B158 : Base137A60 {
    Part16C510* m1C;
    Comp14B158();
    virtual void Update();
    virtual ~Comp14B158();
};

Comp14B158::~Comp14B158()
{
    delete m1C;
}
