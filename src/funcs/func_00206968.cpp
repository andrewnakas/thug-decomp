struct Obj_00206968 {
    char pad0[0x2B8];
    void* m2B8;
    char pad2BC[0x31C - 0x2BC];
    int m31C;
    char pad320[8];
    int m328;
    void Stop();
};

extern "C" void* func_00185578(Obj_00206968* o, unsigned int name);
extern "C" void func_002708C0(void* p);
extern "C" void func_001B6B08(void* p);
extern "C" void func_00185128(Obj_00206968* o, int a);

void Obj_00206968::Stop()
{
    if (m31C)
        func_002708C0(func_00185578(this, 0xB5F1E9D2));
    func_001B6B08(m2B8);
    func_00185128(this, 1);
    m328 = 0;
}
