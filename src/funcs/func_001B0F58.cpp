struct Obj_001B0F58;
extern "C" int func_002665C8(void* p);
extern "C" void func_001B0EB8(Obj_001B0F58* o, int a);

struct Obj_001B0F58 {
    char pad[0x1404];
    char m1404[4];
    int Method();
};

int Obj_001B0F58::Method()
{
    int r = func_002665C8(m1404);
    func_001B0EB8(this, 0);
    return r;
}
