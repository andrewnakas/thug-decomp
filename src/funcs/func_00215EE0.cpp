extern void* D_0038FC78;
extern void* D_00392068;
extern "C" bool func_0022EF38(void* mgr);
extern "C" bool func_002A19A8(void* net);
extern "C" void* func_0022E358(void* mgr);
extern "C" int func_0024F860(void* p);

extern "C" bool func_00215EE0(void* params, void* script)
{
    void* mgr = D_0038FC78;
    void* net = D_00392068;
    bool r = false;
    if (func_0022EF38(mgr) && !func_002A19A8(net))
        r = func_0024F860(func_0022E358(mgr)) == 0;
    return r;
}
