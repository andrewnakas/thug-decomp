struct Obj_0025B7B8;
extern "C" float func_00119768(void* p);
extern "C" void func_001197F0(void* p);
extern "C" void* func_00114DD8(void* o);
extern "C" void func_0025B788(Obj_0025B7B8* self, int a, float f0, float f1);

struct Obj_0025B7B8 {
    char pad[0x18];
    void* m18;
    char pad1C[0x60];
    char m7C[4];
    void Fn();
};

void Obj_0025B7B8::Fn()
{
    float a = func_00119768(m7C);
    func_001197F0(m7C);
    func_00114DD8(m18);
    func_0025B788(this, 0, a, func_00119768(m7C));
}
