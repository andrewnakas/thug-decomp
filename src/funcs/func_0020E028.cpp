struct Mgr_0020E028 {
    char pad[0xDC];
    void* mDC;
};
extern Mgr_0020E028* D_00388A70;
extern "C" int func_001E8870(void* params, unsigned int id, void** out, int req);
extern "C" void func_0010A950(Mgr_0020E028* m, void* heap);
extern "C" int func_001E1060(void* p);
extern "C" void func_0010A9B0(Mgr_0020E028* m);

int func_0020E028(void* params, void* script)
{
    void* v = 0;
    func_001E8870(params, 0, &v, 0);
    if (v) {
        func_0010A950(D_00388A70, D_00388A70->mDC);
        int r = func_001E1060(v);
        func_0010A9B0(D_00388A70);
        return r;
    }
    return 0;
}
