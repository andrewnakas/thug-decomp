/* cflags: -fopt-stack */
struct Obj102FD8 {
    Obj102FD8();
};

extern "C" void func_00103000(Obj102FD8* self);

Obj102FD8::Obj102FD8()
{
    func_00103000(this);
}
