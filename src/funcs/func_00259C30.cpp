extern char D_00390AC8[];
extern "C" void* func_00229DF0(void* node);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00259E40(void* list, int a);

struct Obj_00259C30 {
    int m0;
    char m4[4];
    void* Fn(int a, void* node);
};

void* Obj_00259C30::Fn(int a, void* node)
{
    void* p = func_00229DF0(node);
    int v = 0;
    func_001E7E58(p, D_00390AC8, &v, 0);
    func_00259E40(m4, a);
    return m4;
}
