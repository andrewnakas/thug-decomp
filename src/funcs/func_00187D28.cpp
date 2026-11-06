extern void* D_0038C7B0;

struct Obj_00187D28 {
    char pad0[0xC];
    unsigned int mC;
    void Fn(int a, int b);
};

extern "C" void func_00189BC0(void* mgr, Obj_00187D28* o, int a, int b);

void Obj_00187D28::Fn(int a, int b)
{
    func_00189BC0(D_0038C7B0, this, a, b);
    mC |= 2;
}
