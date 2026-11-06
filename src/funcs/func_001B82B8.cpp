extern char D_00362FD0[];
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_001B82B8;
extern "C" void func_00184DD8(Obj_001B82B8* o, int f);

struct Obj_001B82B8 {
    char pad[0x18];
    void* m18;
    char pad1C[0x164 - 0x1C];
    void* m164;
    void Destroy(int flags);
};

void Obj_001B82B8::Destroy(int flags)
{
    m18 = D_00362FD0;
    func_0010A8D8(D_00388A70, m164);
    func_00184DD8(this, flags);
}
