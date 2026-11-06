extern "C" void* func_001A0718(void* p);
extern "C" void func_0011A188(void* p);
extern "C" void func_001A24C8(void* p);
struct Obj_001A0D38 {
    void Run();
};

void Obj_001A0D38::Run()
{
    void* p = func_001A0718(this);
    if (p) {
        func_0011A188(p);
    }
    func_001A24C8(this);
}
