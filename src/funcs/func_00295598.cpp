extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void* func_00291E60(void*);
extern "C" int func_001E9B08(void*, void*, void*, int);

struct Obj_00295598;
extern "C" void func_00295498(Obj_00295598*, void*, void*);

struct Obj_00295598 {
    int Run(void* a, void* b, void* c);
};

int Obj_00295598::Run(void* a, void* b, void* c)
{
    void* st = func_001E6978(func_001190D0(8));
    func_00295498(this, func_00291E60(a), st);
    int r = func_001E9B08(st, b, c, 1);
    if (st) func_001E6AE8(st, 3);
    return r;
}
