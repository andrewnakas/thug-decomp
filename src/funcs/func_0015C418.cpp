/* sym: __13Base_0015C418 = 0x00145548 */
/* sym: _vt$12Der_0015C418 = 0x003606B8 */
extern "C" long func_00168738(unsigned int key, int n);

class Base_0015C418 {
public:
    char pad0[0x48];
    Base_0015C418();
    virtual void F();
};

class Der_0015C418 : public Base_0015C418 {
public:
    int m4C;
    int m50;
    int m54;
    char pad58[0x46C - 0x58];
    int m46C;
    int m470;
    char pad474[0x1098 - 0x474];
    long m1098;
    long m10A0;
    long m10A8;
    Der_0015C418();
    virtual void F();
};

Der_0015C418::Der_0015C418()
{
    m54 = 0;
    m4C = 0;
    m1098 = func_00168738(0xA86285A1, 0x40);
    m10A0 = func_00168738(0xA86285A1, 0x40);
    m10A8 = func_00168738(0xA86285A1, 0x40);
    m46C = 0;
    m470 = 0;
}
