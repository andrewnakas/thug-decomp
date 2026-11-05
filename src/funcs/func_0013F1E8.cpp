struct Obj_0013F1E8 {
    char pad[0x1B0];
    unsigned long m_flags;
    void Set(bool on);
};

void Obj_0013F1E8::Set(bool on)
{
    m_flags = (m_flags & ~(1UL << 5)) | ((unsigned long)(on & 1) << 5);
}
