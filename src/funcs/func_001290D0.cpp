/* sym: _$_13Base_001290D0 = 0x001238D0 */
/* sym: _vt$13Elem_001290D0 = 0x0035CEA8 */
class Base_001290D0 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_001290D0();
};

class Elem_001290D0;
extern "C" void func_00129118(Elem_001290D0* self);

class Elem_001290D0 : public Base_001290D0 {
public:
    virtual void V0();
    virtual ~Elem_001290D0();
};

Elem_001290D0::~Elem_001290D0()
{
    func_00129118(this);
}
