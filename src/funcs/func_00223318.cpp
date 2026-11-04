extern void* D_00388948;
extern char D_0038F930[];
extern char D_00371BB0[];
extern char D_0038F938[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_001071B8(void* mgr, int id, int a);
extern "C" void func_00107CA0(void* obj, int a, int b);

bool func_00223318(void* params)
{
    int id;
    int a;
    int b;
    func_001E7E58(params, D_0038F930, &id, 1);
    func_001E7E58(params, D_00371BB0, &a, 1);
    func_001E7E58(params, D_0038F938, &b, 1);
    void* obj = func_001071B8(D_00388948, id, 0);
    if (obj) {
        func_00107CA0(obj, a, b);
        return true;
    }
    return false;
}
