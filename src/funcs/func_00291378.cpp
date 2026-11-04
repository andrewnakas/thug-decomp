/* cflags: -fopt-stack */
struct Sub_00291378 {
    char pad[0x80];
};

extern "C" void func_00260640(Sub_00291378* self);

struct Obj_00291378 {
    char pad0[0x1C];
    int m1C;
    int m20;
    char pad24[0x30 - 0x24];
    Sub_00291378 m_sub[4];
    void Clear();
};

void Obj_00291378::Clear() {
    func_00260640(&m_sub[0]);
    func_00260640(&m_sub[1]);
    func_00260640(&m_sub[2]);
    func_00260640(&m_sub[3]);
    m1C = 0;
    m20 = 0;
}
