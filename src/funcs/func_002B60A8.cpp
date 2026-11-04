struct Mgr_002B60A8 {
    int m0;
    void* m4;
};

extern Mgr_002B60A8* D_00392068;
extern "C" int func_002D2D38(void* p);
extern "C" void func_002B3A78(Mgr_002B60A8* m);

int func_002B60A8() {
    Mgr_002B60A8* m = D_00392068;
    if (func_002D2D38(m->m4) == 0) {
        func_002B3A78(m);
    }
    return 1;
}
