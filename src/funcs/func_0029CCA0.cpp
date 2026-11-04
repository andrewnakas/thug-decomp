extern char D_00377670[];
struct Obj_0029CCA0;
extern "C" void func_0029CE58(Obj_0029CCA0* o);
extern "C" void func_00184DD8(Obj_0029CCA0* o, int f);

struct Obj_0029CCA0 {
    char pad[0x18];
    void* m18;
    void Destroy(int flags);
};

void Obj_0029CCA0::Destroy(int flags)
{
    m18 = D_00377670;
    func_0029CE58(this);
    func_00184DD8(this, flags);
}
