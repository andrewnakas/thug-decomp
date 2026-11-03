extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_002C70D0(void* p);
extern "C" void func_002C7288(void* p, int f);
extern "C" void func_002BD7D8(void* p, int v);
extern "C" void func_002BD628(void* p, int v);
extern "C" void func_002C95E8(void* p);
extern "C" void func_002BD838(void* p);
extern "C" void* func_002CC830();
extern "C" void func_002CC178(void* p);

struct Sub_002C4CB8 {
    int m0;
    void* m4;
    void* Get() { return m4; }
};

struct Obj_002C4CB8 {
    char pad0[0x7C];
    Sub_002C4CB8 m7C;
    char pad84[0x1C];
    void* mA0;
    void Start(int a, int b, int c);
};

void Obj_002C4CB8::Start(int a, int b, int c)
{
    if (a) {
        func_002BD7D8(m7C.Get(), 0);
    } else {
        if (mA0) func_002C7288(mA0, 3);
        mA0 = 0;
        func_002BD628(m7C.Get(), b);
    }
    if (c && !mA0) {
        mA0 = func_002C70D0(func_0010A638(D_00388A70, 0xE0, 1, 0));
    }
    if (mA0) func_002C95E8(mA0);
    func_002BD838(m7C.Get());
    func_002CC178(func_002CC830());
}
