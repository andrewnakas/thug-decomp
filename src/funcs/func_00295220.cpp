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

struct Entry_00295220 {
    char pad[0x350];
    Entry_00295220();
    ~Entry_00295220();
};

struct Comp_00295220;
extern "C" void func_00296550(Comp_00295220*);
extern "C" void func_002965D8(Comp_00295220*);

struct Comp_00295220 : public Component {
    int m1C;
    Entry_00295220 m20[50];
    int mA5C0;
    int mA5C4;
    int mA5C8;
    Comp_00295220();
    virtual void Refresh();
    virtual ~Comp_00295220();
};

Comp_00295220::Comp_00295220()
{
    m_type = 0x81F01058;
    func_00296550(this);
    func_002965D8(this);
    mA5C4 = 0;
    mA5C8 = 0;
}
