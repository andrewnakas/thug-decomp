struct Mgr_002D84F0 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D84F0* D_00392068;
extern "C" void func_002D7738(void* p);

int func_002D84F0() {
    func_002D7738(D_00392068->mC);
    return 1;
}
