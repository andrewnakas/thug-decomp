extern char D_0035F148[];

struct Obj_00149AB0 {
    char pad[0x10];
    void* m_vt;
};

extern "C" void func_00138D38(Obj_00149AB0* self, int a, int b);

extern "C" Obj_00149AB0* func_00149AB0(Obj_00149AB0* self, int a)
{
    func_00138D38(self, a, 1);
    self->m_vt = D_0035F148;
    return self;
}
