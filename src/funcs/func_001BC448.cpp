extern "C" void func_001BBF80(void* a, void* b);

struct Obj_001BC448 {
    int m0[7];
    void* m_1C;
    int m20[3];
    void* m_2C;
    void Run();
};

void Obj_001BC448::Run()
{
    func_001BBF80(m_2C, m_1C);
}
