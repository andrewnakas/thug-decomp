struct Mgr_002D5430 {
    char pad0[0x8];
    void* m8;
};

extern Mgr_002D5430* D_00392068;
extern "C" void func_002D4C20(void* p);

int func_002D5430() {
    func_002D4C20(D_00392068->m8);
    return 1;
}
