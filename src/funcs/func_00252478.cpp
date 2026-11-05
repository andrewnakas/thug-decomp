struct Obj_00252478;
extern "C" int func_002526C0(Obj_00252478* self);

struct Obj_00252478 {
    int m0;
    int m4;
    int m8;
    int mC;
    void Fn();
};

void Obj_00252478::Fn()
{
    int v = func_002526C0(this);
    mC = v;
    m8 = v;
}
