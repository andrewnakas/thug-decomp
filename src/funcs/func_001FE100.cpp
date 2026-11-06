struct Obj_001FE100 {
    char pad[0x4290];
    int m_busy;
    char pad4294[0x42A4 - 0x4294];
    void* m_lock;
    void Run();
};
extern "C" void func_0031BCE0(void* lock);
extern "C" int func_0031BCC0(void* lock);
extern "C" int func_00201288(Obj_001FE100* self);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void func_00201028(Obj_001FE100* self);

void Obj_001FE100::Run()
{
    func_0031BCE0(m_lock);
    if (!func_00201288(this))
        func_003267F8();
    m_busy = 1;
    func_00201028(this);
    if (!func_00201288(this))
        func_00326938();
    m_busy = 0;
    func_0031BCC0(m_lock);
}
