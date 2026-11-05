extern void* D_0038FC78;
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" void func_0022E3E8(void* self, int v);

bool Cmd_0022EFA0(void* params, void* script)
{
    void* mgr = D_0038FC78;
    int v;
    func_001E8A30(params, 0, &v, 1);
    func_0022E3E8(mgr, v);
    return true;
}
