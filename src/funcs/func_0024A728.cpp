extern char D_00373E20[];

extern "C" void func_00103F28(const char* fmt);
extern "C" void* func_00240850();
extern "C" void func_0023D608(void* game, int a);

class Base_0024A728 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void Refresh();
};

class Obj_0024A728 : public Base_0024A728 {
public:
    char pad18[0x8C];
    int m_A4;
    int m_A8;
    char padAC[8];
    int m_B4;
    char padB8[0x10];
    int m_C8;
    int m_CC;
    int m_D0;

    bool Next();
};

extern "C" void func_0024A860(Obj_0024A728* self);
extern "C" bool func_00248800(Obj_0024A728* self, unsigned int name);

bool Obj_0024A728::Next()
{
    func_00103F28(D_00373E20);
    func_0023D608(func_00240850(), m_C8);
    func_0024A860(this);
    func_00248800(this, 0x90FF204D);
    m_A8++;
    m_D0++;
    if (m_D0 >= 4 && m_B4 < 3) {
        m_D0 = 0;
        m_B4++;
    }
    m_CC = 0;
    m_A4 = 1;
    Refresh();
    return true;
}
