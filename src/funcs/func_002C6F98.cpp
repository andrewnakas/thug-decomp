extern int D_00392820;
extern "C" int func_0010FC30();
extern "C" void func_002C60A8(void* p);

struct Obj_002C6F98 {
    char pad0[0x20];
    void* m20;
    void Tick();
};

void Obj_002C6F98::Tick()
{
    void* p = m20;
    int start = D_00392820;
    D_00392820 += func_0010FC30() - start;
    func_002C60A8(p);
}
