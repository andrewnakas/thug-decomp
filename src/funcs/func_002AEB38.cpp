struct Park_002AEB38;
extern "C" Park_002AEB38* func_002C0368();
extern "C" void func_002BCE40(Park_002AEB38* p, int v, int a);
extern "C" void* func_002BCE20(Park_002AEB38* p, int v);
extern "C" void func_001053C8(void* p, int v);

struct Obj_002AEB38 {
    int m0;
    bool Run();
};

bool Obj_002AEB38::Run()
{
    func_002BCE40(func_002C0368(), m0, 1);
    func_001053C8(func_002BCE20(func_002C0368(), 0), 15000);
    return true;
}
