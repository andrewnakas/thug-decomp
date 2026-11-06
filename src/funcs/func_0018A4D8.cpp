extern void* D_00389A30;
extern void* D_0038C7B0;
extern "C" void* func_0012E438(void* mgr, void* params, unsigned int key);
extern "C" void* func_001895B0(void* mgr, void* obj);
extern "C" int func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" void func_00189628(void* mgr, int key, void* e);

extern "C" bool func_0018A4D8(void* params, void* script)
{
    void* obj = func_0012E438(D_00389A30, params, 0x40C698AF);
    void* mgr = D_0038C7B0;
    void* set = func_001895B0(mgr, obj);
    int id;
    func_001E8398(params, 0x1E93946B, &id, 1);
    func_00189628(mgr, id, set);
    return true;
}
