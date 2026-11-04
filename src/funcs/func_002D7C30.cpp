extern char D_0037C6A8[];
extern char D_0037C6C0[];

extern "C" void func_002D6880();
extern "C" void func_002D6958();
extern "C" void func_002D69A8();
extern "C" void func_002D6FA8();
extern "C" void func_002D6FB0();
extern "C" void func_002D6FB8();
extern "C" void func_002D6FE8();

struct Head_002D7C30 {
    int m0;
    unsigned int m4;
    int m8;
    Head_002D7C30* mC;
    Head_002D7C30* m10;
    void* m14;
    void Init() {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        mC = this;
        m10 = this;
        m14 = D_0037C6A8;
    }
};

struct Task_002D7C30 {
    char pad[0x18];
    void* m18;
    void (*m1C)();
    void* m20;
};

struct Pool_002D7C30 {
    char pad[0xF4];
    int mF4;
};

extern Pool_002D7C30* D_00388A70;
extern "C" int func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002E8788(void* p, int n);
extern "C" void func_002E8818(void* p, int i, void (*f)(), void* o);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* p, int v);

static inline Task_002D7C30* MakeT_002D7C30(void* mem, void (*f)(), void* o)
{
    Task_002D7C30* t = (Task_002D7C30*)mem;
    func_001047F8(t, 0);
    t->m18 = D_0037C6C0;
    t->m1C = f;
    t->m20 = o;
    return t;
}

struct Obj_002D7C30 {
    int m0;
    int m4;
    int m8;
    Task_002D7C30* mC;
    int m10;
    Head_002D7C30 m14;
    Obj_002D7C30* Init();
};

Obj_002D7C30* Obj_002D7C30::Init()
{
    m14.Init();
    func_0010A950(D_00388A70, D_00388A70->mF4);
    func_002E8788(this, 0x27B0);
    func_002E8818(this, 0, func_002D6880, this);
    func_002E8818(this, 1, func_002D6958, this);
    func_002E8818(this, 2, func_002D69A8, this);
    func_002E8818(this, 3, func_002D6FA8, this);
    func_002E8818(this, 4, func_002D6FB0, this);
    func_002E8818(this, 5, func_002D6FB8, this);
    mC = MakeT_002D7C30(func_001046B0(0x24), func_002D6FE8, this);
    m10 = 0;
    m8 = 0;
    m4 = 0;
    func_0010A9B0(D_00388A70);
    return this;
}
