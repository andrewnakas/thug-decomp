extern void* D_0038FC78;
extern "C" void* func_0022E368(void* self, int index);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00261E70(void* obj, int v);

bool Cmd_002206B8(void* params, void* script)
{
    void* obj = func_0022E368(D_0038FC78, 0);
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_00261E70(obj, v);
    return true;
}
