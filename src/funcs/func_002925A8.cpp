struct Elem_002925A8 {
    int m0;
    int m4;
    Elem_002925A8() {}
};

struct Obj_002925A8;
extern "C" void func_00292630(Obj_002925A8* o);

struct Obj_002925A8 {
    Elem_002925A8 m0[8];
    Obj_002925A8();
};

Obj_002925A8::Obj_002925A8()
{
    func_00292630(this);
}
