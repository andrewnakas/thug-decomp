extern "C" void func_001198D0(void* o, int a, float f0, float f1, int type, float f2, float f3);

struct Obj_0025ADB8 {
    char pad[0x3C];
    int m3C;
    char m40[4];
    void Fn(float v);
};

void Obj_0025ADB8::Fn(float v)
{
    m3C = 0;
    func_001198D0(m40, 0, 0.0f, v, 0, 0.0f, 1.0f);
}
