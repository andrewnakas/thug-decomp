extern void* D_00392068;
extern void* D_0038FC78;
extern "C" bool func_002A1A38(void* net);
extern "C" void* func_0022E358(void* mgr);
extern "C" int func_0024F5F8(void* p);
extern "C" void func_0022D728(void* mgr, int a);

bool Cmd_00214D30(void* params, void* script)
{
    void* mgr = D_0038FC78;
    if (func_002A1A38(D_00392068))
        func_0022D728(mgr, func_0024F5F8(func_0022E358(mgr)));
    return true;
}
