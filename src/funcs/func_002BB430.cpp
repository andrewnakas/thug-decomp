struct Slot_002BB430 {
    char pad0[8];
    void* m8;
};

struct Obj_002BB430;
extern "C" Slot_002BB430* func_002BB3B0(Obj_002BB430* o, int idx);

struct Obj_002BB430 {
    char pad0[0x30];
    unsigned int m30;
    void* GetKey(int i);
};

void* Obj_002BB430::GetKey(int i)
{
    if (!(i < m30 && i >= 0))
        return 0;
    return func_002BB3B0(this, i)->m8;
}
