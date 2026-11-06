extern "C" void func_001BBED8(void* a, void* b);

struct Obj_001BC428 {
    int m0[7];
    void* m_1C;
    int m20[3];
    void* m_2C;
    void Run();
};

void Obj_001BC428::Run()
{
    func_001BBED8(m_2C, m_1C);
}
