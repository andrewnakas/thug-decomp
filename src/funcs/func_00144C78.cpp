extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern char D_0035EE08[];

struct Obj_00144C78 {
    char pad[0xA18];
    void* m_vt;
};

extern "C" void func_00144C78(Obj_00144C78* self, int chrg)
{
    self->m_vt = D_0035EE08;
    if (chrg & 1)
        func_0010A8D8(D_00388A70, self);
}
