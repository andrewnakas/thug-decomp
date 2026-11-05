extern void* D_0038FC78;
extern "C" void* func_0022E368(void* a, void* b);
extern "C" int func_002623B8(void* a);

extern "C" bool func_0021B390(void* a)
{
    void* p = func_0022E368(D_0038FC78, a);
    return p && func_002623B8(p);
}
