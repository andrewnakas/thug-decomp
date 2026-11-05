extern "C" int func_0010A298(void* o, void* a, int b);

struct Obj_00109060 {
    int m0[5];
    void* m_14;
    bool Test(void* a);
};

bool Obj_00109060::Test(void* a)
{
    return func_0010A298(m_14, a, 1) != 0;
}
