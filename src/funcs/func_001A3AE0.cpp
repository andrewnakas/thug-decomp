extern "C" void func_001DEF68(void* p);

struct Base1A3AE0 {
    int m_pad[6];
    Base1A3AE0();
    virtual ~Base1A3AE0();
};

struct Comp1A3AE0 : Base1A3AE0 {
    void* m1C[3];
    Comp1A3AE0();
    virtual void Update();
    virtual ~Comp1A3AE0();
};

Comp1A3AE0::~Comp1A3AE0()
{
    for (int i = 0; i < 3; i++) {
        if (m1C[i]) {
            func_001DEF68(m1C[i]);
        }
    }
}
