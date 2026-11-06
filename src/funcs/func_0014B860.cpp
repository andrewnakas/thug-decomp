/* sym: _vt$12Obj_0014B860 = 0x0035F420 */
/* sym: _$_13Base_0014B860 = 0x00114A88 */
struct Base_0014B860 {
    char m_data[0x24];
    virtual ~Base_0014B860();
};

struct Obj_0014B860 : Base_0014B860 {
    virtual void Update();
    virtual ~Obj_0014B860();
};

Obj_0014B860::~Obj_0014B860()
{
}
