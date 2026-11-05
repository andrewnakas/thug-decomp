extern "C" int func_0021B318(void* params);
extern "C" void* func_0021B348();
extern "C" int func_002392B8(void* p);

bool func_0021DBD0(void* params, void* script)
{
    int n = func_0021B318(params);
    void* p = func_0021B348();
    if (p && func_002392B8(p) < n)
        return true;
    return false;
}
