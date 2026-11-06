extern char D_0037AE48[];
extern void* D_00388A70;
struct Obj_002C9F48;
extern "C" void func_002CA650(Obj_002C9F48* o);
extern "C" void func_002BA9E0();
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002C9F48 {
    char pad[0xC];
    void* mC;
    void Destroy(int flags);
};

void Obj_002C9F48::Destroy(int flags)
{
    func_002CA650(this);
    mC = D_0037AE48;
    func_002BA9E0();
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
