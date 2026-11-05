struct Obj_00251330;
extern "C" void func_00250C40(Obj_00251330* self);

struct Obj_00251330 {
    int m0;
    int m4;
    int m8;
    void Fn();
};

void Obj_00251330::Fn()
{
    m8++;
    func_00250C40(this);
}
