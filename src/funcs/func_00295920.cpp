extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001F0370(char*, int, int, int);
extern char D_00377438[];

struct Comp_00295920 {
    int m0, m4, m8, mC, m10, m14;
    virtual void v0();
    virtual void v1();
    virtual void v2(void*);
};

struct Obj_00295920;
extern "C" void func_002959D8(Obj_00295920*);

struct Obj_00295920 {
    char pad0[0xA5C4];
    Comp_00295920* mA5C4;
    void Stop(int flag);
};

void Obj_00295920::Stop(int flag)
{
    if (flag) {
        func_001F0370(D_00377438, 0, 0, 0);
        return;
    }
    void* st = func_001E6978(func_001190D0(8));
    func_001E7200(st, 0x67E6859A, 0);
    mA5C4->v2(st);
    if (st) func_001E6AE8(st, 3);
    func_002959D8(this);
}
