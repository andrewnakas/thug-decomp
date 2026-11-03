extern "C" void* func_001317D0(void* p);
extern "C" void func_00135220(void* p, int v);

struct Obj_002B6F30 {
    void* m0;
    char pad4[0x2C];
    int m30;
    void Set(int v, int apply);
};

void Obj_002B6F30::Set(int v, int apply) {
    m30 = v;
    if (apply == 1) {
        func_00135220(func_001317D0(m0), v);
    }
}
