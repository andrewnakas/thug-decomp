/* sym: _$_13Base_0025A878 = 0x0025A8E0 */
/* sym: _$_12Sub_0025B358 = 0x001196D8 */
/* sym: _vt$12Obj_0025B358 = 0x00375698 */
struct Base_0025A878 {
    char pad[0x14];
    virtual void V0();
    virtual ~Base_0025A878();
};

struct Sub_0025B358 {
    int m0;
    ~Sub_0025B358();
};

struct Obj_0025B358 : Base_0025A878 {
    char pad18[0x7C - 0x18];
    Sub_0025B358 m7C;
    virtual void V0();
    virtual ~Obj_0025B358();
};

Obj_0025B358::~Obj_0025B358()
{
}
