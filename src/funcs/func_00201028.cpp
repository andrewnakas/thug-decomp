extern "C" int func_0031BBC0();
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);
extern "C" void func_00200F88(void* self);

struct Obj_00201028 {
    char pad0[0x4298];
    int m_sema;
    char pad429C[0x42D4 - 0x429C];
    int m_quit;
    char pad42D8[0x4358 - 0x42D8];
    virtual void V0();
    virtual void V1();
    virtual int Process();
    void Run();
};

void Obj_00201028::Run()
{
    while (1) {
        func_0031BBC0();
        if (m_quit) {
            break;
        }
        func_0031BCE0(m_sema);
        Process();
        func_0031BCC0(m_sema);
        func_0031BBC0();
        if (m_quit) {
            break;
        }
        func_0031BCE0(m_sema);
        func_00200F88(this);
        func_0031BCC0(m_sema);
    }
}
