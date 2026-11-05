/* sym: __13Base_0025B310 = 0x0025A878 */
/* sym: __12Sub_0025B310 = 0x00119690 */
/* sym: _vt$12Obj_0025B310 = 0x00375698 */
struct Base_0025B310 {
    char pad[0x14];
    Base_0025B310();
    virtual void V0();
};

struct Sub_0025B310 {
    int m0;
    Sub_0025B310();
};

struct Obj_0025B310 : Base_0025B310 {
    char pad18[0x24];
    int m3C;
    int m40;
    char pad44[0x34];
    int m78;
    Sub_0025B310 m7C;
    Obj_0025B310();
    virtual void V0();
};

Obj_0025B310::Obj_0025B310()
{
    m78 = 0;
    m3C = 0;
    m40 = 0;
}
