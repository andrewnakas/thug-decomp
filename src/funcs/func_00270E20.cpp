extern "C" void func_00270E40(void* self, int a);

struct Obj_00270E20 {
    char pad[0x20];
    int m20;
    void Run();
};

void Obj_00270E20::Run()
{
    func_00270E40(this, m20);
}
