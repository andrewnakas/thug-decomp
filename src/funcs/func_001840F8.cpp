extern "C" void func_001849E8(void* p, void* a);
extern "C" void func_001E6AC8(void* p, void* a);
struct Obj_001840F8 {
    char pad[0x24];
    void* m24;
    void Run(void* a);
};

void Obj_001840F8::Run(void* a)
{
    func_001849E8(this, a);
    func_001E6AC8(m24, a);
}
