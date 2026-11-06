extern "C" void func_00270DD8(void* self, int a);

struct Obj_00270DB8 {
    char pad[0x20];
    int m20;
    void Run();
};

void Obj_00270DB8::Run()
{
    func_00270DD8(this, m20);
}
