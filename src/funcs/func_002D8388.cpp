struct Mgr_002D8388 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D8388* D_00392068;
extern char D_0037C5C8[];
extern char D_0037C5D8[];
extern char D_0037C5E8[];
extern "C" void* func_002A6070(Mgr_002D8388* m);
extern "C" int func_001F0D78(const char* s);
extern "C" int func_00203018(void* p, int a, int b);
extern "C" void func_002D7EC0(void* p);

int func_002D8388() {
    Mgr_002D8388* m = D_00392068;
    void* obj = func_002A6070(m);
    int a = func_001F0D78(D_0037C5C8);
    int b = func_001F0D78(D_0037C5D8);
    int r = func_00203018(obj, a, b);
    if (r != func_001F0D78(D_0037C5E8)) {
        return 0;
    }
    func_002D7EC0(m->mC);
    return 1;
}
