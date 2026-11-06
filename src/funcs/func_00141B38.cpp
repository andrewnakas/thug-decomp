extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern char D_0035ED80[];

struct Obj_00141B38 {
    char pad[0x190];
    void* m_vt;
};

extern "C" void func_00141B38(Obj_00141B38* self, int chrg)
{
    self->m_vt = D_0035ED80;
    if (chrg & 1)
        func_0010A8D8(D_00388A70, self);
}
