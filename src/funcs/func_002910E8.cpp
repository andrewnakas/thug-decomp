/* cflags: -fopt-stack */
struct Sub_002910E8 {
    char pad[0x80];
};

extern "C" void func_002605F8(Sub_002910E8* self);

struct Obj_002910E8 {
    char pad0[0x1C];
    int m1C;
    int m20;
    char pad24[0x30 - 0x24];
    Sub_002910E8 m_sub[4];
    void Reset();
};

void Obj_002910E8::Reset() {
    func_002605F8(&m_sub[0]);
    func_002605F8(&m_sub[1]);
    func_002605F8(&m_sub[3]);
    func_002605F8(&m_sub[2]);
    m1C = 0;
    m20 = 0;
}
