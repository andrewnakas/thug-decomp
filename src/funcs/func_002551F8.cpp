struct Obj_002551F8;
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E70C0(void* params, unsigned int name, Obj_002551F8* value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_0021E790(void* params, int a);
extern "C" void func_001E6AE8(void* p, int flags);

struct Obj_002551F8 {
    char pad[0x80];
    unsigned int m80;
};

struct Cmd_002551F8 {
    Obj_002551F8* m0;
    bool Fn();
};

bool Cmd_002551F8::Fn()
{
    Obj_002551F8* o = m0;
    void* p = func_001E6978(func_001190D0(8));
    func_001E70C0(p, 0, o);
    func_001E7360(p, 0, o->m80);
    func_0021E790(p, 0);
    if (p) func_001E6AE8(p, 3);
    return true;
}
