extern "C" void func_0010BEB8(void* p);

struct Obj_0017DAA0 {
    char pad0[0x2C];
    void* m2C;
    char pad30[0x34 - 0x30];
    void* m34;
    void* m38;
    char pad3C[0x44 - 0x3C];
    void* m44;
    void Fn();
};

void Obj_0017DAA0::Fn()
{
    func_0010BEB8(m34);
    func_0010BEB8(m2C);
    func_0010BEB8(m38);
    func_0010BEB8(m44);
    m34 = 0;
    m2C = 0;
    m38 = 0;
}
