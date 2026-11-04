struct Mgr_002D8588 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D8588* D_00392068;
extern "C" void func_002D7A08(void* p);

int func_002D8588() {
    func_002D7A08(D_00392068->mC);
    return 1;
}
