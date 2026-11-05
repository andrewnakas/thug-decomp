extern "C" void func_001048F0(void* p);

struct Obj_002C6D80 {
    char pad0[0x3C];
    void* m3C;
    void* m40;
    void* m44;
    void Free();
};

void Obj_002C6D80::Free()
{
    func_001048F0(m3C);
    func_001048F0(m44);
}
