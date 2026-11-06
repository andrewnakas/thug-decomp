extern void* D_0038FC78;

extern "C" void* func_0022E358(void* mgr);
extern "C" int func_0024F1D8(void* p);
extern "C" int func_0024EF70(void* p);

bool func_00217390_Check()
{
    void* mgr = D_0038FC78;
    bool r = false;
    if (func_0024F1D8(func_0022E358(mgr)))
        r = func_0024EF70(func_0022E358(mgr)) == 0;
    return r;
}
