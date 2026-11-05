/* sym: _vt$12Obj_00260520 = 0x00375B28 */
struct Obj_00260520;
extern "C" void func_002605F8(Obj_00260520* self);

struct Obj_00260520 {
    char pad[0x70];
    Obj_00260520();
    virtual void V0();
};

Obj_00260520::Obj_00260520()
{
    func_002605F8(this);
}
