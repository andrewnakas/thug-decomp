extern "C" void func_002B6A40(void* heap);
extern "C" void* func_002B6A68(int size);
extern "C" void* func_002B6208(void* p);
extern "C" void func_002B6AB8();

struct Obj_002B67D0 {
    char pad0[0x10];
    void* m10;
    void* Create();
};

void* Obj_002B67D0::Create() {
    func_002B6A40(m10);
    void* r = func_002B6208(func_002B6A68(0x30));
    func_002B6AB8();
    return r;
}
