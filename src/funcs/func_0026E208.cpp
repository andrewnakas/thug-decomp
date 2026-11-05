extern "C" int func_0026E158(void* self);
extern "C" int func_0026DF90(void* a);
extern "C" void func_0026DF70(void* p, int v);

struct Obj_0026E208 {
    int m0;
    void* m4;
    void Apply(void* a);
};

void Obj_0026E208::Apply(void* a)
{
    if (func_0026E158(this))
        func_0026DF70(m4, func_0026DF90(a));
}
