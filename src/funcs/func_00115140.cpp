/* sym: _$_13Base_00115140 = 0x00114F88 */
/* sym: _vt$12Obj_00115140 = 0x0035C4C8 */
class Res_00115140 {
public:
    int m0;
    int m4;
    virtual ~Res_00115140();
};

class Base_00115140 {
public:
    int m0;
    int m4;
    virtual ~Base_00115140();
};

extern "C" void func_00132038(Res_00115140* r);

class Obj_00115140 : public Base_00115140 {
public:
    Res_00115140* mC;
    Res_00115140* m10;
    virtual void Run();
    virtual ~Obj_00115140();
};

Obj_00115140::~Obj_00115140()
{
    func_00132038(m10);
    delete m10;
    delete mC;
}
