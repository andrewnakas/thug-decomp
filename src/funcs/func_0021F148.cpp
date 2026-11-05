struct Obj_0021F148 {
    int m0;
    char m4[4];
};

extern void* D_0038FC78;

extern "C" int func_001E7DE8(void* params, unsigned int name, unsigned int* out, int req);
extern "C" Obj_0021F148* func_0022E3C8(void* game, unsigned int id);
extern "C" int func_001E8870(void* params, unsigned int name, int* out, int req);
extern "C" void* func_001200E0(void* p);
extern "C" void func_00123530(void* p, int v);

bool Cmd_0021F148(void* params, void* script)
{
    unsigned int id;
    func_001E7DE8(params, 0x67E6859A, &id, 1);
    void* sub = func_0022E3C8(D_0038FC78, id)->m4;
    int v;
    func_001E8870(params, 0x7D99F28D, &v, 1);
    func_00123530(func_001200E0(sub), v);
    return true;
}
