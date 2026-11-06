extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_0018CA30 {
    char pad0[0xC];
    void* mC;
    char pad10[0x264 - 0x10];
    void* m264;
    void* m268;
    void* m26C;
    void Fn();
};

void Obj_0018CA30::Fn()
{
    m264 = func_00185578(mC, 0x222756D5);
    m268 = func_00185578(mC, 0x72AD7B23);
    m26C = func_00185578(mC, 0xCE0CA665);
}
