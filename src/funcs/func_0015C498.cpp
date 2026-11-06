extern char D_003606B8[];

struct Obj_0015C498 {
    char pad[0x48];
    void* m_vt;
};

extern "C" void func_00145610(Obj_0015C498* self, int chrg);

extern "C" void func_0015C498(Obj_0015C498* self, int chrg)
{
    self->m_vt = D_003606B8;
    func_00145610(self, chrg);
}
