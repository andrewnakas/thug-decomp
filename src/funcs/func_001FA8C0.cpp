extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
struct Obj_001FA8C0 {
    int m0;
    void* m4;
};

void func_001FA8C0(Obj_001FA8C0* self, int flags)
{
    if (self->m4)
        func_0010A8D8(D_00388A70, self->m4);
    if (flags & 1)
        func_0010A8D8(D_00388A70, self);
}
