struct Obj_0024EFE0;
extern "C" void* func_00240850();
extern "C" unsigned int func_0024F938(Obj_0024EFE0* self);
extern "C" int func_0024F970(Obj_0024EFE0* self, unsigned int v);
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_002445E8(void* g, int v);

struct Obj_0024EFE0 {
    void Fn(int a);
};

void Obj_0024EFE0::Fn(int a)
{
    void* mgr = func_00240850();
    void* g = func_0023BAD8(mgr, func_0024F970(this, func_0024F938(this)), 0);
    if (g) func_002445E8(g, a);
}
