/* sym: __13Base_00209240 = 0x00101F38 */
struct Base_00209240 {
    char pad[0xC0];
    Base_00209240();
};
struct Sub_00209240 {
    int m0;
    int m4;
    int m8;
    Sub_00209240()
    {
        m4 = 0;
        m8 = 0;
        m0 = 0;
    }
};
struct Obj_00209240 : Base_00209240 {
    Sub_00209240 mC0;
    Obj_00209240();
};
extern "C" void func_00209308(Obj_00209240* self);

Obj_00209240::Obj_00209240()
{
    func_00209308(this);
}
