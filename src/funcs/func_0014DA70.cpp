extern "C" int func_00170538(void* o);

struct Obj_0014DA70 {
    int m0[8];
    void* m_20;
    int Get();
};

int Obj_0014DA70::Get()
{
    if (m_20)
        return func_00170538(m_20);
    return 0;
}
