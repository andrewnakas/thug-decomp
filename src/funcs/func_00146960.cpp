extern "C" unsigned int func_00170830(void* o);

struct Obj_00146960 {
    int m0[12];
    void* m_30;
    unsigned int Get();
};

unsigned int Obj_00146960::Get()
{
    if (m_30)
        return func_00170830(m_30) | 0xFFFFFF00;
    return 0;
}
