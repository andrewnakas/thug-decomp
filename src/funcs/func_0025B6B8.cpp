extern "C" void func_001198D0(void* o, int a, float f0, float f1, int type, float f2, float f3);

struct Obj_0025B6B8 {
    char pad[0x78];
    int m78;
    char m7C[4];
    void Fn(float v);
};

void Obj_0025B6B8::Fn(float v)
{
    m78 = 0;
    func_001198D0(m7C, 0, 0.0f, v, 0, 0.0f, 1.0f);
}
