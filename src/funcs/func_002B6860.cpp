extern "C" void func_002B6A40(void* heap);
extern "C" void func_002B6228(void* p, int flags);
extern "C" void func_002B6AB8();

struct Obj_002B6860 {
    char pad0[0x10];
    void* m10;
    void Destroy(void* p);
};

void Obj_002B6860::Destroy(void* p) {
    func_002B6A40(m10);
    if (p) {
        func_002B6228(p, 3);
    }
    func_002B6AB8();
}
