struct Obj_002465E8 {
    char pad[0x3C];
    unsigned int m_flags;
};

void func_002465E8(Obj_002465E8* self, int bit)
{
    self->m_flags |= 1 << bit;
}
