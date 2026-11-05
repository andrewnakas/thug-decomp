struct Obj_0024EF70;
extern "C" void* func_00240850();
extern "C" unsigned int func_0024F938(Obj_0024EF70* self);
extern "C" int func_0024F970(Obj_0024EF70* self, unsigned int v);
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" int func_002445F8(void* g);

struct Obj_0024EF70 {
    int Fn();
};

int Obj_0024EF70::Fn()
{
    void* mgr = func_00240850();
    void* g = func_0023BAD8(mgr, func_0024F970(this, func_0024F938(this)), 0);
    if (!g) return 0;
    return func_002445F8(g);
}
