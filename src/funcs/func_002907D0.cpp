/* cflags: -fopt-stack */
extern "C" void func_001848F0(int script, unsigned int checksum, int arg);

struct Obj_002907D0 {
    char pad0[0xC];
    int mC;
    char pad10[0x1C - 0x10];
    int m_flags;
    void Clear();
};

void Obj_002907D0::Clear() {
    m_flags &= ~0x10;
    func_001848F0(mC, 0xAB676175, 0);
}
