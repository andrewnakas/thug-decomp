extern "C" int func_0013C540(void* o);

struct Obj_00135020 {
    int m0[8];
    void* m_20;
    int Get();
};

int Obj_00135020::Get()
{
    if (m_20)
        return func_0013C540(m_20);
    return 0;
}
