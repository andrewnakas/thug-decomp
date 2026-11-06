extern "C" int func_00170518(void* self);

struct Obj_001707D8 {
    int m0[7];
    unsigned int m_flags;
    int m_20;
    int m_24;
    int m28;
    int m_2C;
    void Set(int v);
};

void Obj_001707D8::Set(int v)
{
    if (!func_00170518(this))
        m_2C = v;
}
