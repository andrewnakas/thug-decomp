struct Obj_0026B448 {
    char pad[0x58];
    unsigned int m_flags;
};

void func_0026B448(Obj_0026B448* self, int bit)
{
    self->m_flags |= 1 << bit;
}
