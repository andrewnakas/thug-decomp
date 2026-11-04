struct Slot_002BB7A0 {
    char pad0[8];
    void* m8;
};

struct Obj_002BB7A0;
extern "C" Slot_002BB7A0* func_002BB3B0(Obj_002BB7A0* o, unsigned int idx);
extern "C" void* func_002B6CF8(void* key);
extern "C" void func_002B7150(void* e, void* a);

struct Obj_002BB7A0 {
    char pad0[0x30];
    unsigned int m30;
    void Apply(void* a);
};

void Obj_002BB7A0::Apply(void* a)
{
    for (unsigned int i = 0; i < m30; i++)
        func_002B7150(func_002B6CF8(func_002BB3B0(this, i)->m8), a);
}
