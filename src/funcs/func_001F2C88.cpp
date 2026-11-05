struct Obj_001F2C88 {
    int m0;
    int m4;
    void* m8;
};
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001F3200(Obj_001F2C88* p);

void func_001F2C88(Obj_001F2C88* self, int flags)
{
    if (self->m8)
        func_0010BEB8(self->m8);
    if (flags & 1)
        func_001F3200(self);
}
