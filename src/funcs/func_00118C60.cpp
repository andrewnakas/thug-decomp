extern "C" void func_001848F0(void* dst, int a, int b);

struct Obj_00118C60 {
    int m0[8];
    int m_20;
    int m_24;
    bool Apply(void* dst);
};

bool Obj_00118C60::Apply(void* dst)
{
    func_001848F0(dst, m_20, m_24);
    return true;
}
