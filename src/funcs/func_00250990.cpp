extern void* D_0038FC78;
extern "C" void* func_0022DE70(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);

bool Fn_00250990()
{
    void* p = func_00203360(func_0022DE70(D_0038FC78));
    if (p) {
        if (func_002392B8(p) > 0) return true;
    }
    return false;
}
