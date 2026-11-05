extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

struct Obj_0025AAA8 {
    char pad[0x20];
    int m20;
    char pad24[8];
    int m2C;
    void* Fn();
};

void* Obj_0025AAA8::Fn()
{
    void* p = func_001E6978(func_001190D0(8));
    func_001E7200(p, 0x8DDE72C0, m20);
    func_001E7200(p, 0xB8CA12C5, m2C);
    return p;
}
