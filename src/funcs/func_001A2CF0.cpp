extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_001A2CF0 {
    char pad0[0xC];
    void* mC;
    char pad10[0x68 - 0x10];
    void* m68;
    void* m6C;
    void* m70;
    void Fn();
};

void Obj_001A2CF0::Fn()
{
    m6C = func_00185578(mC, 0x222756D5);
    m68 = func_00185578(mC, 0xCE0CA665);
    m70 = func_00185578(mC, 0x286A8D26);
}
