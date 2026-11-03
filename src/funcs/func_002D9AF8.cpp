struct Mgr_002D9AF8 {
    char pad0[0x10];
    void* m10;
};

extern Mgr_002D9AF8* D_00392068;
extern "C" void func_002D9370(void* p);

void func_002D9AF8() {
    func_002D9370(D_00392068->m10);
}
