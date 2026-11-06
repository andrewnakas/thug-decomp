extern "C" void func_001BB080(void* p, int n, void* o);
struct Obj_001BB4B8 {
    char pad[0xD0];
    void* mD0;
    void Run();
};

void Obj_001BB4B8::Run()
{
    func_001BB080(mD0, 0, this);
}
