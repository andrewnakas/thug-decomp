/* cflags: -fopt-stack */
struct Sub_002910A8 {
    char pad[0x80];
};

extern "C" void func_002606A0(Sub_002910A8* self);

struct Obj_002910A8 {
    char pad0[0x30];
    Sub_002910A8 m_sub[4];
    void Run();
};

void Obj_002910A8::Run() {
    func_002606A0(&m_sub[0]);
    func_002606A0(&m_sub[1]);
    func_002606A0(&m_sub[2]);
    func_002606A0(&m_sub[3]);
}
