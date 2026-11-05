extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E050(void* self);
extern "C" void func_00263258(void* obj, bool v);

bool Cmd_002233B0(void* params, void* script)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 1);
    func_00263258(func_0022E050(D_0038FC78), v != 0);
    return true;
}
