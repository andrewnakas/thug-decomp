extern void* D_0038C308;
extern char D_003709D0[];
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void func_00103F28(void* name, int v);
extern "C" void func_00182978(void* o, int v);

bool func_00215308(void* params, void* script)
{
    void* o = D_0038C308;
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_00103F28(D_003709D0, v);
    func_00182978(o, v);
    return true;
}
