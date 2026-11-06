struct Obj_001730A8 {
    char pad0[0x138];
    char m138[0x18];
    unsigned short m150;
    unsigned short m152;
    unsigned short m154;
    unsigned short m156;
};

extern int D_00393F5C;
extern "C" void func_00164860(int type, void* data, int a, int b, int c);

extern "C" void func_001730A8(Obj_001730A8* self)
{
    self->m154 = D_00393F5C;
    D_00393F5C += self->m150;
    self->m156 = D_00393F5C;
    D_00393F5C += self->m152;
    func_00164860(6, self->m138, (short)self->m154, (short)self->m156, -1);
}
