extern char D_0037C1B0[];
extern char D_0037C198[];
extern char D_0037C1C8[];

struct List_002D4E18 {
    int m0;
    unsigned int m4;
    int m8;
    List_002D4E18* mC;
    List_002D4E18* m10;
    char* m14;
    void Init()
    {
        m14 = D_0037C1B0;
        m4 = 0xFFFFFFFF;
        mC = this;
        m10 = this;
        m8 = 0;
    }
};

struct Ref_002D4E18 {
    int m0;
    int m4;
    char* m8;
    void Init()
    {
        m8 = D_0037C198;
        m4 = 0;
    }
};

extern "C" void* func_001047F8(void* p, int v);

struct Task_002D4E18 {
    char pad0[0x18];
    char* m18;
    void (*m1C)(void*);
    void* m20;
    void Init(void (*cb)(void*), void* owner)
    {
        func_001047F8(this, 0);
        m1C = cb;
        m20 = owner;
        m18 = D_0037C1C8;
    }
};

struct Params_002D4E18 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

struct Obj_002D4E18 {
    Task_002D4E18* m0;
    int m4;
    int m8;
    char padC[0x1C - 0xC];
    int m1C;
    char pad20[0x320 - 0x20];
    void* m320;
    char pad324[0x350 - 0x324];
    List_002D4E18 m350;
    char pad368[0x368 - 0x368];
    Ref_002D4E18 m368;
    Obj_002D4E18* Init();
};

extern "C" void* func_001046B0(int size);
extern "C" void func_002D41E0(void* p);
extern "C" void* func_0031BCA0(Params_002D4E18* p);

Obj_002D4E18* Obj_002D4E18::Init()
{
    m350.Init();
    m368.Init();
    m4 = 0;
    m8 = 0;
    m1C = 0;
    Task_002D4E18* t = (Task_002D4E18*)func_001046B0(0x24);
    t->Init(func_002D41E0, this);
    m0 = t;
    Params_002D4E18 prm;
    prm.m8 = 1;
    prm.m4 = 10;
    m320 = func_0031BCA0(&prm);
    return this;
}
