extern void* D_0038FC78;
extern "C" void* func_0022DD38(void* mgr, void* params);
extern "C" int func_00203360(void* p);

int func_0021B348(void* script, void* params)
{
    void* p = func_0022DD38(D_0038FC78, params);
    if (p)
        return func_00203360(p);
    return 0;
}
