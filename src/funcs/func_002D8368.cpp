struct Mgr_002D8368 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D8368* D_00392068;
extern "C" void func_002D7EB8(void* p);

void func_002D8368() {
    func_002D7EB8(D_00392068->mC);
}
