extern "C" void func_002381E0(void* p);
extern "C" void func_00239158(void* p, float f, int a);
extern "C" void func_00239178(void* p, float f, int a);

struct Obj_00277E80 {
    char pad[0x1C];
    void* m1C;
    void Reset();
};

void Obj_00277E80::Reset()
{
    func_002381E0(m1C);
    func_00239158(m1C, 0.0f, 0);
    func_00239178(m1C, 0.0f, 0);
}
