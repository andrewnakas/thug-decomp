extern "C" void func_001E6AC8(void* p);

struct Obj_00250C20 {
    int m_0;
    void* m_data;
    void Run();
};

void Obj_00250C20::Run()
{
    func_001E6AC8(m_data);
}
