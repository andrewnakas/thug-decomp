extern "C" void func_001048F0(void* p);

struct Obj_00253E18 {
    char pad[0x18];
    void* m18;
    char pad1C[0xC];
    void* m28[2];
    void Fn();
};

void Obj_00253E18::Fn()
{
    func_001048F0(m18);
    for (int i = 0; i < 2; i++) func_001048F0(m28[i]);
}
