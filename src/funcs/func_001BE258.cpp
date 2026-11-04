extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_001DADB0(void* p);

struct Ref1BE258 {
    void* p;
    ~Ref1BE258()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

struct Elem1BE258 {
    int m_pad[60];
    Ref1BE258 mF0;
    int mF4[7];
};

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp1BE258 : Base184DD8 {
    int m1C[45];
    Elem1BE258 m_elems[8];
    int m950[48];
    void* mA10;
    int mA14[71];
    Ref1BE258 mB30;
    Comp1BE258();
    virtual void Update();
    virtual ~Comp1BE258();
};

Comp1BE258::~Comp1BE258()
{
    func_001DADB0(mA10);
}
