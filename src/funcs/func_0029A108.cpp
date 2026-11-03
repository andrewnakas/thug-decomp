struct Component {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    Component();
    virtual ~Component();
};

extern char D_003775A0[];
extern char D_003775B8[];
extern "C" void func_0029C5A0(int count, void* name);
extern "C" void func_0029C628(int count, void* name);
extern "C" void func_0029C6B0();
extern "C" void func_0029C718();

struct Comp_0029A108 : public Component {
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    Comp_0029A108();
    virtual void Update();
    virtual ~Comp_0029A108();
};

extern "C" void func_0029A1E8(Comp_0029A108* self);
extern "C" void func_0029B290(Comp_0029A108* self);

Comp_0029A108::Comp_0029A108() {
    m_type = 0x5B509AD3;
    func_0029C5A0(0x190, D_003775A0);
    func_0029C628(0xC8, D_003775B8);
    m1C = 0;
    m20 = 0;
    m34 = 0;
    m30 = 0;
    m24 = 0;
    func_0029A1E8(this);
    func_0029B290(this);
}
