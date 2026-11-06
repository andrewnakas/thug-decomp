extern "C" float func_00144DC0(void* a);

struct C_0025DB50 {
    char m_pad[0xC];
    void* mC;
    char m10[0xB60];
    float mB70;
    bool Check();
};

bool C_0025DB50::Check()
{
    return func_00144DC0(mC) <= mB70;
}
