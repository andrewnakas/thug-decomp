extern "C" unsigned int func_00170830(void* o);

struct Obj_0014D9C0 {
    int m0[8];
    void* m_20;
    unsigned int Get();
};

unsigned int Obj_0014D9C0::Get()
{
    if (m_20)
        return func_00170830(m_20) | 0xFFFFFF00;
    return 0;
}
