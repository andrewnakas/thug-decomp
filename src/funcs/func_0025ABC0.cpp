/* sym: _$_13Base_0025A878 = 0x0025A8E0 */
/* sym: _$_12Sub_0025ABC0 = 0x001196D8 */
/* sym: _vt$12Obj_0025ABC0 = 0x00375630 */
struct Base_0025A878 {
    char pad[0x14];
    virtual void V0();
    virtual ~Base_0025A878();
};

struct Sub_0025ABC0 {
    int m0;
    ~Sub_0025ABC0();
};

struct Obj_0025ABC0 : Base_0025A878 {
    char pad18[0x40 - 0x18];
    Sub_0025ABC0 m40;
    virtual void V0();
    virtual ~Obj_0025ABC0();
};

Obj_0025ABC0::~Obj_0025ABC0()
{
}
