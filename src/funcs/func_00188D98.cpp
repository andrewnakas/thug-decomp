extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0018A6C8(void* p, int flags);

struct Obj_00188D98 {
    char pad0[0xB008];
    void* mB008;
    void Destroy(int flags);
};

void Obj_00188D98::Destroy(int flags)
{
    if (mB008)
        func_0018A6C8(mB008, 3);
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
