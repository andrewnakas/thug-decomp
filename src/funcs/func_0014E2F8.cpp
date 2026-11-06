extern "C" void* func_00170680(void* o);
extern "C" int func_00170518(void* o);
extern "C" int func_00170568(void* o);
extern "C" void* func_00170718(void* o);
extern "C" void func_00172270(void* o, float a, float b, float c, float d, float e, float f, float g, float h);

struct Obj_0014E2F8 {
    char pad0[0x20];
    void* m20;
    void Fn(float a, float b, float c, float d, float e, float f, float g, float h);
};

void Obj_0014E2F8::Fn(float a, float b, float c, float d, float e, float f, float g, float h)
{
    void* p = m20;
    while (!func_00170518(p))
        p = func_00170680(p);
    for (; p; p = func_00170718(p)) {
        if (func_00170568(p))
            func_00172270(p, a, b, c, d, e, f, g, h);
    }
}
