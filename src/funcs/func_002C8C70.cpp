struct Obj_002C8C70;
extern "C" void func_002CDD78(void* p, Obj_002C8C70* o);

struct Obj_002C8C70 {
    char pad0[0x6C];
    void* m6C;
    void Run();
};

void Obj_002C8C70::Run()
{
    if (m6C)
        func_002CDD78(m6C, this);
}
