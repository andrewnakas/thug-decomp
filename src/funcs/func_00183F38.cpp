struct Obj_00183F38 {
    char pad0[0x14];
    void* m14;
    void Fn(int a, int b);
};

extern "C" void func_00184A40(Obj_00183F38* self);
extern "C" void func_001F0FC0(void* p, int a, int b);

void Obj_00183F38::Fn(int a, int b)
{
    func_00184A40(this);
    func_001F0FC0(m14, a, b);
}
