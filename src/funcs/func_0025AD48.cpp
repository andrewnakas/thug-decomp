extern "C" void func_001198D0(void* o, int a, float f0, float f1, int type, float f2, float f3);

struct Obj_0025AD48 {
    char pad[0x3C];
    float* m3C;
    char m40[4];
    void Fn(float* p, int type, int flag);
};

void Obj_0025AD48::Fn(float* p, int type, int flag)
{
    m3C = p;
    if (!flag) func_001198D0(m40, 0, 0.0f, *p, type, 0.0f, 1.0f);
    else func_001198D0(m40, 0, *p - 1.0f / 60.0f, 0.0f, type, 0.0f, 1.0f);
}
