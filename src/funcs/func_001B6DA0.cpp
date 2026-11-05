extern char D_00362C68[];
struct Obj_001B6DA0;
extern "C" void func_001B7338(Obj_001B6DA0* o);
extern "C" void func_00184DD8(Obj_001B6DA0* o, int f);

struct Obj_001B6DA0 {
    char pad[0x18];
    void* m18;
    void Destroy(int flags);
};

void Obj_001B6DA0::Destroy(int flags)
{
    m18 = D_00362C68;
    func_001B7338(this);
    func_00184DD8(this, flags);
}
