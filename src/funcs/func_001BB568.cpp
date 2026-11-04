struct Task1BB568 {
    int m0[6];
    virtual void V0();
    virtual void V1();
    virtual ~Task1BB568();
};

extern "C" int func_00104968(Task1BB568* t);
extern "C" void func_001048F0(Task1BB568* t);

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp1BB568 : Base184DD8 {
    int m1C[320];
    Task1BB568* m51C;
    Task1BB568* m520;
    Comp1BB568();
    virtual void Update();
    virtual ~Comp1BB568();
};

Comp1BB568::~Comp1BB568()
{
    if (m51C) {
        if (func_00104968(m51C)) func_001048F0(m51C);
        delete m51C;
    }
    if (m520) {
        if (func_00104968(m520)) func_001048F0(m520);
        delete m520;
    }
}
