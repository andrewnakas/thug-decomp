extern void* D_0038FC78;
struct Obj_0021D278 {
    int m0;
    char m4[0x48];
    char m4C[4];
};
extern "C" Obj_0021D278* func_0022E368(void* mgr, void* params);
extern "C" void func_0011FE10(void* a, void* b);

bool func_0021D278(void* params, void* script)
{
    Obj_0021D278* o = func_0022E368(D_0038FC78, params);
    func_0011FE10(o->m4, o->m4C);
    return true;
}
