struct Obj_001D72E8 {
    int m_0;
    int m_4;
    Obj_001D72E8* m_8;
    void Set(Obj_001D72E8* p);
};

void Obj_001D72E8::Set(Obj_001D72E8* p)
{
    m_8 = p;
    if (p) {
        m_0 = p->m_0;
    }
}
