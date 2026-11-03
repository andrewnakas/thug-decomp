struct Mgr_002D8418 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D8418* D_00392068;
extern "C" void func_002D8070(void* p);

int func_002D8418() {
    func_002D8070(D_00392068->mC);
    return 1;
}
