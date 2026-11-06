/* sym: _vt$12Obj_00146870 = 0x0035F090 */
/* sym: _$_13Base_00146870 = 0x00134E70 */
struct Base_00146870 {
    char m_data[0x28];
    virtual ~Base_00146870();
};

struct Obj_00146870 : Base_00146870 {
    virtual void Update();
    virtual ~Obj_00146870();
};

Obj_00146870::~Obj_00146870()
{
}
