extern "C" void func_00188C20(void* p);

struct Obj_001F11E0 {
    char pad[0xdc];
    void* m_p;
    void Run();
};

void Obj_001F11E0::Run()
{
    func_00188C20(m_p);
}
