/* sym: _vt$13Comp_00253C98 = 0x003752D8 */
/* sym: _$_13Base_00253C98 = 0x00182A10 */
class Part_00253C98 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~Part_00253C98() = 0;
};

struct Base_00253C98 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void Update();
    virtual ~Base_00253C98();
};

struct Comp_00253C98 : Base_00253C98 {
    Part_00253C98* m18;
    char pad1C[0x28 - 0x1C];
    Part_00253C98* m28[2];
    virtual void Update();
    virtual ~Comp_00253C98();
};

Comp_00253C98::~Comp_00253C98()
{
    if (m18)
        delete m18;
    for (int i = 0; i < 2; i++) {
        if (m28[i])
            delete m28[i];
        m28[i] = 0;
    }
}
