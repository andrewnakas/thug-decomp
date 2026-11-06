struct Obj_0019DEF0 {
    char pad0[0x50];
    float m50;
    char pad54[0x64 - 0x54];
    void* m64;
    char pad68[0xC0 - 0x68];
    char mC0[0x100 - 0xC0];
    float m100;
    bool Fn();
};

extern "C" void func_00103930(void* q, void* m, float t);

bool Obj_0019DEF0::Fn()
{
    float t;
    m50 += m100;
    if (m50 >= 0.5f)
        t = 1.0f;
    else
        t = m50 + m50;
    func_00103930(m64, mC0, t);
    return t == 1.0f;
}
