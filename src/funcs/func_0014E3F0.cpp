extern "C" void* func_00170680(void* o);
extern "C" int func_00170518(void* o);
extern "C" int func_00170568(void* o);
extern "C" void* func_00170718(void* o);
extern "C" void func_001722B8(void* o, int v);

struct Obj_0014E3F0 {
    char pad0[0x20];
    void* m20;
    void Fn(int v);
};

void Obj_0014E3F0::Fn(int v)
{
    void* p = m20;
    while (!func_00170518(p))
        p = func_00170680(p);
    for (; p; p = func_00170718(p)) {
        if (func_00170568(p))
            func_001722B8(p, v);
    }
}
