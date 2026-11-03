struct Obj1BC8B8 {
    int m_pad[100];
    virtual ~Obj1BC8B8();
};

extern "C" void func_001427C0(void* mgr, Obj1BC8B8* o);
extern "C" void func_00142328(Obj1BC8B8* o);
extern void* D_00389C34;

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Comp1BC8B8 : Base184DD8 {
    int m1C;
    Obj1BC8B8* m20;
    Comp1BC8B8();
    virtual void Update();
    virtual ~Comp1BC8B8();
};

Comp1BC8B8::~Comp1BC8B8()
{
    if (m20) {
        func_001427C0(D_00389C34, m20);
        func_00142328(m20);
        delete m20;
    }
}
