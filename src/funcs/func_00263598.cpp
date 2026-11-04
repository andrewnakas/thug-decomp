struct Slot_00263598;

extern void* D_00388A70;
extern char D_00375D68[];

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Slot_00263598* func_0026D0A8(void* mem);

struct Obj_00263598 {
    char pad0[0x5C8];
    Slot_00263598* m_slots[21];
    int m_used[21];
    void* m_vtbl;
};

extern "C" void func_002636E8(Obj_00263598* self, int a);

Obj_00263598* func_00263598(Obj_00263598* self)
{
    self->m_vtbl = D_00375D68;
    for (unsigned int i = 0; i < 21; i++) {
        self->m_slots[i] = func_0026D0A8(func_0010A638(D_00388A70, 0x1C, 1, 0));
        self->m_used[i] = 0;
    }
    func_002636E8(self, 1);
    return self;
}
