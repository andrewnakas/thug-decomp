extern void* D_00390828;
extern char D_00370EB8[];
extern "C" int func_001E88F8(void* params, void* name, int* out, int req);
extern "C" void func_00253EC0(void* o, int v);

bool func_00218C80(void* params, void* script)
{
    void* o = D_00390828;
    int v;
    func_001E88F8(params, D_00370EB8, &v, 1);
    func_00253EC0(o, v);
    return true;
}
