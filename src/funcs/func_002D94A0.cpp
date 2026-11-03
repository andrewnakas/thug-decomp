struct Mgr_002D94A0 {
    char pad0[0x10];
    void* m10;
};

extern Mgr_002D94A0* D_00392068;
extern "C" void func_002D9340(void* p);

void func_002D94A0() {
    func_002D9340(D_00392068->m10);
}
