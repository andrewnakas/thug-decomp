extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Obj1A5338 {
    int m_pad[65];
    virtual ~Obj1A5338();
};

struct Part25A340 {
    ~Part25A340();
};

struct Comp1A5338 : Base184DD8 {
    int m1C[120];
    void* m1FC;
    int m200[7];
    Obj1A5338* m21C;
    Part25A340* m220;
    Comp1A5338();
    virtual void Update();
    virtual ~Comp1A5338();
};

Comp1A5338::~Comp1A5338()
{
    if (m21C) {
        delete m21C;
        m21C = 0;
    }
    if (m1FC) {
        func_0010A8D8(D_00388A70, m1FC);
        m1FC = 0;
    }
    if (m220) {
        delete m220;
        m220 = 0;
    }
}
