extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0010BEB8(void* p);
struct Obj_00207DF8 {
    char pad[0x28];
    void* m28;
    void* m2C;
};

void func_00207DF8(Obj_00207DF8* self, int flags)
{
    if (self->m28)
        func_0010A8D8(D_00388A70, self->m28);
    if (self->m2C)
        func_0010BEB8(self->m2C);
    if (flags & 1)
        func_0010A8D8(D_00388A70, self);
}
