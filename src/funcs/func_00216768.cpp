extern void* D_0038FC78;
extern "C" void func_0013B590();
extern "C" void* func_0022DE70(void* mgr, unsigned int i);
extern "C" void* func_00203360(void* p);
extern "C" void func_0023AB50(void* p);

extern "C" bool func_00216768(void* params, void* script)
{
    void* mgr = D_0038FC78;
    func_0013B590();
    for (unsigned int i = 0; i < 8; i++) {
        void* p = func_0022DE70(mgr, i);
        if (p)
            func_0023AB50(func_00203360(p));
    }
    return true;
}
