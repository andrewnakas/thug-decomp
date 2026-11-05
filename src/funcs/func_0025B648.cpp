extern "C" void func_001198D0(void* o, int a, float f0, float f1, int type, float f2, float f3);

struct Obj_0025B648 {
    char pad[0x78];
    float* m78;
    char m7C[4];
    void Fn(float* p, int type, int flag);
};

void Obj_0025B648::Fn(float* p, int type, int flag)
{
    m78 = p;
    if (!flag) func_001198D0(m7C, 0, 0.0f, *p, type, 0.0f, 1.0f);
    else func_001198D0(m7C, 0, *p - 1.0f / 60.0f, 0.0f, type, 0.0f, 1.0f);
}
