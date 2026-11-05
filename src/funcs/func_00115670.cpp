extern "C" void func_0013D950(void* o, int on);

struct Obj_00115670 {
    int m0[3];
    void* m_C;
    void On();
};

void Obj_00115670::On()
{
    if (m_C)
        func_0013D950(m_C, 1);
}
