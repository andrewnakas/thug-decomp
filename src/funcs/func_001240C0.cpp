struct Obj1240C0 {
    char pad[0xC];
    unsigned int m_flags;
    char pad2[0x194 - 0x10];
    float m194;
    void Set194(float v);
};

void Obj1240C0::Set194(float v)
{
    m194 = v;
    m_flags |= 0x9000;
}
