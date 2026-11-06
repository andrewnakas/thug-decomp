extern char D_0035F2F0[];

struct Obj_0014A468 {
    int m_0;
    void* m_vt;
    int m_8;
};

extern "C" void func_00135768(Obj_0014A468* self);

extern "C" Obj_0014A468* func_0014A468(Obj_0014A468* self)
{
    func_00135768(self);
    self->m_vt = D_0035F2F0;
    self->m_8 = 0;
    return self;
}
