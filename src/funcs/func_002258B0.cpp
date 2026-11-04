extern void* D_0038FC78;

extern "C" void* func_0022E050(void* mgr);
extern "C" int func_002628F0(void* skater);
extern "C" void* func_0022DE70(void* mgr, int id);
extern "C" void func_00206B60(void* obj, void* params);
extern "C" void func_00206D58(void* obj, void* params);
extern "C" void func_00206E40(void* obj, void* params);
extern "C" void func_00262D10(void* skater, void* a, int b);

void func_002258B0(void* params, void* a)
{
    void* mgr = D_0038FC78;
    void* skater = func_0022E050(mgr);
    void* obj = func_0022DE70(mgr, func_002628F0(skater));
    func_00206B60(obj, params);
    func_00206D58(obj, params);
    func_00206E40(obj, params);
    func_00262D10(skater, a, 1);
}
