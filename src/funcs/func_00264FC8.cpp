/* sym: _vt$12Der_00264FC8 = 0x00376018 */
/* sym: _vt$12Sub_00264FC8 = 0x00376030 */
/* sym: __12Der_00264FC8i = 0x00264FC8 */
extern "C" int func_00265238(void* self); /* really returns 1 */

class Lnk_00264FC8 {
public:
    int m0;
    void* m4;
    int m8;
    Lnk_00264FC8* mC;
    Lnk_00264FC8* m10;
    Lnk_00264FC8(void* d)
    {
        m4 = d;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual void V0();
};

class Sub_00264FC8 : public Lnk_00264FC8 {
public:
    Sub_00264FC8() : Lnk_00264FC8((void*)0xFFFFFFFF) {}
    virtual void V1();
};

class Der_00264FC8 : public Lnk_00264FC8 {
public:
    int m18;
    char pad1C[0x28 - 0x1C];
    Sub_00264FC8 m28;
    Der_00264FC8(int a);
    virtual void V1();
};

Der_00264FC8::Der_00264FC8(int a) : Lnk_00264FC8(this)
{
    m18 = a;
    func_00265238(this);
}
