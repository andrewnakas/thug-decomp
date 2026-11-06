struct Obj_0013EE48 {
    char pad[0x1B0];
    unsigned long m_flags;
    void Set(bool on);
};

void Obj_0013EE48::Set(bool on)
{
    m_flags = (m_flags & ~(1UL << 3)) | ((unsigned long)(on & 1) << 3);
}
