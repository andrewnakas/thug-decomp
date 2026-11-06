extern void* D_00393EF4;
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_00139468(void* mgr, unsigned int id);
extern "C" void func_00122658(void* p);

extern "C" bool func_00122CB0(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0x7D99F28D, &id, 0);
    void* p = func_00139468(D_00393EF4, id);
    if (p) {
        func_00122658(p);
    }
    return true;
}
