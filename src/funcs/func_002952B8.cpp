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

struct Entry_002952B8 {
    char pad[0x350];
    Entry_002952B8();
    ~Entry_002952B8();
};

extern "C" void func_001F0370(char*, int, int, int);
extern char D_00377438[];

struct Comp_002952B8 : public Component {
    int m1C;
    Entry_002952B8 m20[50];
    int mA5C0;
    int mA5C4;
    int mA5C8;
    Comp_002952B8();
    virtual void Refresh();
    virtual ~Comp_002952B8();
};

Comp_002952B8::~Comp_002952B8()
{
    func_001F0370(D_00377438, 0, 0, 0);
}
