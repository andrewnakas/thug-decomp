extern "C" void func_002B6580(void* list);
extern "C" void func_002B6780(void* list);

struct Obj_002B8FA8 {
    char pad0[0x2C];
    char m2C[0x10];
    void Clear();
};

void Obj_002B8FA8::Clear() {
    func_002B6580(m2C);
    func_002B6780(m2C);
}
