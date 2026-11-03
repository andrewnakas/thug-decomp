extern "C" void func_002B6580(void* list);
extern "C" void func_002B6780(void* list);

struct Obj_002B7FE8 {
    char pad0[0x64];
    char m64[0x10];
    void Clear();
};

void Obj_002B7FE8::Clear() {
    func_002B6580(m64);
    func_002B6780(m64);
}
