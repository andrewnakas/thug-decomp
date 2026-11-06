struct Mgr_0013BDF0 {
    int m0[8];
};

extern int D_00393EFC;
extern Mgr_0013BDF0 D_003C38E0;
extern char D_0035E438[];
extern "C" void func_001022D8(Mgr_0013BDF0* m);
extern "C" void func_00103F28(const char* msg);

extern "C" Mgr_0013BDF0* func_0013BDF0()
{
    if (!D_00393EFC) {
        func_001022D8(&D_003C38E0);
        D_00393EFC = 1;
    }
    func_00103F28(D_0035E438);
    return &D_003C38E0;
}
