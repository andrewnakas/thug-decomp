struct Obj_002465D0 {
    char pad[0x38];
    unsigned int m_flags;
};

void func_002465D0(Obj_002465D0* self, int bit)
{
    self->m_flags |= 1 << bit;
}
