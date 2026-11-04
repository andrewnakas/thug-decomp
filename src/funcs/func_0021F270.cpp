extern void* D_0038FC78;

extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E050(void* mgr);
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" int func_00262388(void* obj);
extern "C" void func_002628F8(void* skater, int id);

bool func_0021F270(void* params)
{
    int id;
    if (!func_001E8A30(params, 0xA1DC81F9, &id, 0))
        func_001E8A30(params, 0, &id, 1);
    void* skater = func_0022E050(D_0038FC78);
    if (func_00262388(func_0022E368(D_0038FC78, 0)) == id)
        return false;
    func_002628F8(skater, id);
    return true;
}
