struct Obj_0017ECB8 {
    int m0;
    int m_flags;
    char pad8[0x20];
    char m28[0x1C];
    unsigned short m44;
    unsigned short m46;
    unsigned short m48;
    unsigned short m4A;
};

extern int D_00393F5C;
extern "C" void func_00164860(int type, void* data, int a, int b, int c);

extern "C" void func_0017ECB8(Obj_0017ECB8* self)
{
    if ((self->m_flags >> 1) & 1) {
        self->m48 = D_00393F5C;
        D_00393F5C += self->m44;
        self->m4A = D_00393F5C;
        D_00393F5C += self->m46;
        func_00164860(6, self->m28, (short)self->m48, (short)self->m4A, -1);
    }
}
