extern "C" void* func_0013CA80(void* key, int arg);

struct Obj_00144CB0 {
    int m0;
    void* m_4;
    void* m_8;
    char pad[0xA00];
    int m_A0C;
    void Set(int v);
};

void Obj_00144CB0::Set(int v)
{
    m_A0C = v;
    if (!v)
        m_4 = func_0013CA80(m_8, 1);
}
