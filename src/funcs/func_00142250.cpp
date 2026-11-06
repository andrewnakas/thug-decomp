class Obj_00142250;
extern "C" void func_00142440(Obj_00142250* self);
extern "C" void func_00141B70(Obj_00142250* self);

class Obj_00142250 {
public:
    char pad0[0x190];
    virtual void V0();
    virtual void Reset();
    void Restart();
};

void Obj_00142250::Restart()
{
    func_00142440(this);
    func_00141B70(this);
    Reset();
}
