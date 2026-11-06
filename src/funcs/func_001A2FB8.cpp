extern char D_003623F0[];
extern "C" bool func_001E84E8(void* params, char* name, void** out, int required);
extern "C" void* func_0026BA78(void* p);

struct Obj_001A2FB8 {
    char pad0[0xC4];
    void* mC4;
    void Fn(void* params);
};

void Obj_001A2FB8::Fn(void* params)
{
    void* v;
    if (func_001E84E8(params, D_003623F0, &v, 0))
        mC4 = func_0026BA78(v);
}
