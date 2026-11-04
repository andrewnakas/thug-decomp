extern "C" void func_00107CA0(void* p, int i, int v);

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp1BA878 : Base184DD8 {
    int m1C[7];
    void* m38;
    Comp1BA878();
    virtual void Update();
    virtual ~Comp1BA878();
};

Comp1BA878::~Comp1BA878()
{
    if (m38) {
        for (int i = 1; i != -1; i--) func_00107CA0(m38, i, 0);
    }
}
