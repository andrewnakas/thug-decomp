extern "C" void func_002B6B20(void* heap);
extern "C" void func_002B6268(void* p, int flags);
extern "C" void func_002B6B98();

struct Obj_002B68A0 {
    char pad0[0x14];
    void* m14;
    void Destroy(void* p);
};

void Obj_002B68A0::Destroy(void* p) {
    func_002B6B20(m14);
    if (p) {
        func_002B6268(p, 3);
    }
    func_002B6B98();
}
