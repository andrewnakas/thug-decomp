extern "C" void func_00270C98(void* self, int v);

struct Obj_00270C68 {
    char pad[0x1C];
    unsigned int m1C;
    int m20;
    int m24;
    void Run();
};

void Obj_00270C68::Run()
{
    func_00270C98(this, m1C < 2 ? m24 : m20);
}
