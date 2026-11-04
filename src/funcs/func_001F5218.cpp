extern "C" void func_0032A3E8(void*, int, int);
extern "C" void func_0032A738(void*, int, void*, int);
extern "C" void func_001F5380(void*);
extern "C" void func_001F5B90(void*, int, int, int, int, int);
extern "C" void func_001F5800();
extern "C" void func_001F5828();
extern "C" void func_001F5860();
extern "C" void func_001F5890();
extern "C" void func_001F58C0();

struct Obj_001F5218 {
    char pad[0x48];
    char m48[1];
    int Init(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

int Obj_001F5218::Init(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    func_0032A3E8(this, a1, a2);
    func_0032A738(this, 0, (void*)func_001F5800, 0);
    func_0032A738(this, 1, (void*)func_001F5828, 0);
    func_0032A738(this, 2, (void*)func_001F5860, 0);
    func_0032A738(this, 3, (void*)func_001F5890, 0);
    func_0032A738(this, 5, (void*)func_001F58C0, 0);
    func_001F5380(this);
    func_001F5B90(m48, a3, a4, a5, a6, a7);
    return 1;
}
