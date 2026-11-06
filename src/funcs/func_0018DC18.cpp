extern "C" int func_0013D8A8(void* p);

class Comp_0018DC18 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
};

class Obj_0018DC18 : public Comp_0018DC18 {
public:
    char pad1C[0x260 - 0x1C];
    void* m260;
    void Fn();
};

extern "C" void func_0018CAF0(Obj_0018DC18* self);

void Obj_0018DC18::Fn()
{
    V1();
    if (m260 && func_0013D8A8(m260))
        func_0018CAF0(this);
}
