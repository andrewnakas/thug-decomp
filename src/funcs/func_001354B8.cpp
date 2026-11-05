extern "C" void func_0013C708(void* o, int v);

struct Src_001354B8 {
    int m0[2];
    int m_8;
};

struct Obj_001354B8 {
    int m0[8];
    void* m_20;
    Src_001354B8* m_24;
    bool Attach(Src_001354B8* s);
};

bool Obj_001354B8::Attach(Src_001354B8* s)
{
    if (m_24)
        return false;
    m_24 = s;
    if (m_20)
        func_0013C708(m_20, s->m_8);
    return true;
}
