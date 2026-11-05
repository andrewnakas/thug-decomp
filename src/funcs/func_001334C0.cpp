extern "C" void func_00331A9C(void* p);

class Obj_001334C0 {
public:
    char pad[0x280];
    virtual void V0();
    virtual int V1();
    void Run();
};

void Obj_001334C0::Run()
{
    func_00331A9C(this);
    V1();
}
