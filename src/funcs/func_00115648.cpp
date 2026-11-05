extern "C" void func_0013D950(void* o, int on);

struct Obj_00115648 {
    int m0[3];
    void* m_C;
    void Off();
};

void Obj_00115648::Off()
{
    if (m_C)
        func_0013D950(m_C, 0);
}
