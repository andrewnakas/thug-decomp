struct Heap_002617C8 {
    char pad0[0xEC];
    void* m_EC;
};

extern Heap_002617C8* D_00388A70;

extern "C" void func_0010A950(Heap_002617C8* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002617C8* mgr);
extern "C" void* func_0011FD78(void* table, void* key);
extern "C" void func_001E6B30(void* s);
extern "C" void* func_001E9D70(void* s, void* src);

struct Obj_002617C8 {
    int m_0;
    char m_4[4];
};

extern "C" void* func_00262330(Obj_002617C8* self, unsigned int name);
extern "C" void* func_00262358(Obj_002617C8* self);
extern "C" void* func_00261B38(Obj_002617C8* self, void* s);

void* func_002617C8(Obj_002617C8* self, void* key)
{
    func_0010A950(D_00388A70, D_00388A70->m_EC);
    void* src = func_0011FD78(self->m_4, key);
    func_001E6B30(func_00262330(self, 0xD544AA2D));
    void* a = func_001E9D70(func_00262330(self, 0xD544AA2D), src);
    void* t = func_00262358(self);
    func_001E6B30(t);
    void* r = func_00261B38(self, func_001E9D70(t, a));
    func_0010A9B0(D_00388A70);
    return r;
}
