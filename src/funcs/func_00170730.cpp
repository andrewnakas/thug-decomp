extern "C" void func_001705A0(void* self, bool on);

struct Obj_00170730 {
    int m0[7];
    unsigned int m_flags;
    int m_20;
    int m_24;
    int m28;
    int m_2C;
    void Set(int v);
};

void Obj_00170730::Set(int v)
{
    m_24 = v;
    func_001705A0(this, v != 0);
}
