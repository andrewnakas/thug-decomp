extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE8C8(void* p, void* a, void* b, void* owner);

struct Obj_0024FE20 {
    char pad[0x14];
    void* m14;
    void Fn(void* a, void* b);
};

void Obj_0024FE20::Fn(void* a, void* b)
{
    if (!m14) m14 = func_001EE428(func_00121960(0xF4));
    func_001EE8C8(m14, a, b, 0);
}
