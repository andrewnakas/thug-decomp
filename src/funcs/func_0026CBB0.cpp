extern "C" void func_001041B8(void* p);

struct Obj_0026CBB0 {
    char pad[0x50];
    int m_sub;
    void Run();
};

void Obj_0026CBB0::Run()
{
    func_001041B8(&m_sub);
}
