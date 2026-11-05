extern "C" int func_00109B78(void* o, void* a, int b);

struct Obj_001083B0 {
    int m0[3];
    void* m_C;
    bool Test(void* a);
};

bool Obj_001083B0::Test(void* a)
{
    return func_00109B78(m_C, a, 0) != 0;
}
