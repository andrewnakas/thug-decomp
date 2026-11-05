/* sym: __13Base_0025F300 = 0x00183CF8 */
/* sym: __12Sub_0025F300 = 0x00114C30 */
/* sym: _vt$13Node_0025F300 = 0x003758E0 */
/* sym: _vt$12Obj_0025F300 = 0x00375888 */
struct Base_0025F300 {
    int m0;
    int m4;
    Base_0025F300();
    virtual void V0();
};

struct Node_0025F300 {
    int m0;
    unsigned int m4;
    int m8;
    Node_0025F300* mC;
    Node_0025F300* m10;
    virtual void V0();
    Node_0025F300()
    {
        m4 = 0xFFFFFFFF;
        mC = this;
        m10 = this;
        m8 = 0;
    }
};

struct Sub_0025F300 {
    int m0;
    Sub_0025F300();
};

struct Obj_0025F300 : Base_0025F300 {
    char padC[0x3C];
    Node_0025F300 m48;
    Sub_0025F300 m60;
    char pad64[0xC0];
    int m124;
    Obj_0025F300();
    virtual void V0();
};

Obj_0025F300::Obj_0025F300()
{
    m124 = 0;
}
