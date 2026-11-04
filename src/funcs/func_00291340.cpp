/* cflags: -fopt-stack */
extern "C" void func_001E6AE8(void* obj, int mode);

struct Obj_00291340 {
    char pad0[0x24];
    void* m24;
    void Release();
};

void Obj_00291340::Release() {
    if (m24) {
        func_001E6AE8(m24, 3);
        m24 = 0;
    }
}
