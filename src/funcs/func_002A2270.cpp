extern "C" void* func_002A6070();
extern "C" int func_001F0D78(void* name);
extern "C" void* func_00202EF8(void* mgr, int id);
extern "C" int func_001E8890(void* obj, void* name, int* out, int flag);
extern char D_00378378[];
extern char D_00378318[];

extern "C" int func_002A2270() {
    int out;
    void* mgr = func_002A6070();
    void* obj = func_00202EF8(mgr, func_001F0D78(D_00378378));
    func_001E8890(obj, D_00378318, &out, 1);
    return out;
}
