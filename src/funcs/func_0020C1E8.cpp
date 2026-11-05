extern void* D_00388A70;
struct Obj_0020C1E8 {
    char pad[0x2C];
    int m2C;
    char pad2[4];
    void* m34;
};
extern "C" Obj_0020C1E8* func_0010ACE0(void* mgr, unsigned int id);
extern "C" int func_0010C258(void* p);

int func_0020C1E8(int add)
{
    Obj_0020C1E8* o = func_0010ACE0(D_00388A70, 0x0C7800B0);
    void* h = o->m34;
    if (add)
        return o->m2C + func_0010C258(h);
    return func_0010C258(h);
}
