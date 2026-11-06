extern "C" void* func_00186CF8(void* mgr);
extern "C" void func_00185470(void* emit, void* params);
extern "C" void func_001853F0(void* emit, void* arr, void* params);
extern "C" void func_00185500(void* emit);

extern "C" void* func_00186D60(void* mgr, void* arr, void* params, int stopped)
{
    void* e = func_00186CF8(mgr);
    func_00185470(e, params);
    func_001853F0(e, arr, params);
    if (stopped) {
        func_00185500(e);
    }
    return e;
}
