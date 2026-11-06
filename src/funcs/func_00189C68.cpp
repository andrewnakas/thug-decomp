extern "C" void func_00189018(void* q);

struct Obj_00189C68 {
    int m0[8];
    char m_20[4];
    void Flush();
};

void Obj_00189C68::Flush()
{
    func_00189018(m_20);
}
