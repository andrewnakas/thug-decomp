struct Obj_00135590 {
    int m0;
    unsigned int m_flags;
    void Clear(unsigned int f);
};

void Obj_00135590::Clear(unsigned int f)
{
    m_flags &= ~f;
}
