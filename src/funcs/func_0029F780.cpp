extern "C" int func_002A8268(void* p);
extern "C" int func_002A49B8(void* p);
extern "C" void func_002A4A58(void* p, int v);
extern "C" void func_002A8260(void* p, int v);
extern void* D_00392068;

extern "C" void func_0029F780() {
    void* p = D_00392068;
    if (func_002A8268(p) == 1) {
        func_002A4A58(p, func_002A49B8(p));
        func_002A8260(p, 0);
    }
}
