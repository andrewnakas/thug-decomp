/* cflags: -fopt-stack */
struct Sub_00291068 {
    char pad[0x80];
};

extern "C" void func_00260620(Sub_00291068* self);

struct Obj_00291068 {
    char pad0[0x30];
    Sub_00291068 m_sub[4];
    void Run();
};

void Obj_00291068::Run() {
    func_00260620(&m_sub[0]);
    func_00260620(&m_sub[1]);
    func_00260620(&m_sub[2]);
    func_00260620(&m_sub[3]);
}
