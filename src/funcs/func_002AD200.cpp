extern "C" int func_00202778(void* p);
extern "C" void func_00202220(void* p);

struct Obj_002AD200 {
    char pad[0x14];
    void* m14;
    int Run();
};

int Obj_002AD200::Run()
{
    if (func_00202778(m14))
        func_00202220(m14);
    return 1;
}
