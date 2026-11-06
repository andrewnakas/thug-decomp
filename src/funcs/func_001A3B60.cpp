extern char D_00362470[];
extern "C" bool func_001E84E8(void* params, char* name, void** out, int required);
extern "C" void* func_0026BA78(void* p);

struct Obj_001A3B60 {
    char pad0[0x2C];
    void* m2C;
    void Fn(void* params);
};

void Obj_001A3B60::Fn(void* params)
{
    void* v;
    if (func_001E84E8(params, D_00362470, &v, 0))
        m2C = func_0026BA78(v);
}
