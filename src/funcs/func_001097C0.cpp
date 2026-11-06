extern void* D_00388A44;
extern "C" bool func_001E8870(void* params, unsigned int name, int* out, int required);
extern "C" void func_00109240(void* self, int v);

bool Cmd_001097C0(void* params, void* script)
{
    void* mgr = D_00388A44;
    int v;
    func_001E8870(params, 0, &v, 1);
    func_00109240(mgr, v);
    return true;
}
