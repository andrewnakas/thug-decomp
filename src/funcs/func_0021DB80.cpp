extern "C" int func_0021B318();
extern "C" void* func_0021B348();
extern "C" int func_002392B8(void* p);

extern "C" bool func_0021DB80()
{
    int a = func_0021B318();
    void* p = func_0021B348();
    if (p) {
        if (a < func_002392B8(p))
            return true;
    }
    return false;
}
