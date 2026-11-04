struct Mgr_002D8440 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D8440* D_00392068;
extern "C" void func_002D7FB0(void* p);

int func_002D8440() {
    func_002D7FB0(D_00392068->mC);
    return 1;
}
