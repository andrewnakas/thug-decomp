extern "C" void func_00270D50(void* self, int a, int b);

struct Obj_00270D30 {
    char pad[0x1C];
    int m1C;
    void Run(int a);
};

void Obj_00270D30::Run(int a)
{
    func_00270D50(this, a, m1C);
}
