extern void* D_0038FC78;
extern char D_003716D8[];
extern char D_003716E8[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" int func_00229668(unsigned int name, int a);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_0022E8E8(void* mgr, int id, bool flag);

bool func_0021D378(void* params)
{
    int id = -1;
    unsigned int name;
    if (!func_001E7E58(params, D_003716D8, &id, 0)) {
        if (func_001E84E8(params, D_003716E8, &name, 0))
            id = func_00229668(name, 1);
    }
    int i = id;
    void* mgr = D_0038FC78;
    func_0022E8E8(mgr, i, func_001E8708(params, 0xD6F06BF6));
    return true;
}
