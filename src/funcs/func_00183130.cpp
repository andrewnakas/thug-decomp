inline void* operator new(unsigned int, void* p) { return p; }
extern void* D_00388948;
extern "C" void* func_001046B0(int size);
extern "C" void* func_00107270(void* p, int i);
extern "C" void func_001832A0();

struct TB_00183130 {
    char pad[0x18];
    TB_00183130(int priority);
    virtual void V0();
};

struct Task_00183130 : TB_00183130 {
    void* m_func;
    void* m_owner;
    Task_00183130(void* f, void* owner) : TB_00183130(2000) { m_func = f; m_owner = owner; }
    virtual void V0();
};

struct P_00183130 {
    void* m0;
    char pad[0x94 - 4];
    P_00183130();
};

struct C_00183130 {
    int m0;
    Task_00183130* m_task;
    P_00183130 m_pads[2];
    int m130;
    C_00183130();
};

C_00183130::C_00183130()
{
    void* src = D_00388948;
    m_task = new (func_001046B0(0x24)) Task_00183130((void*)func_001832A0, this);
    for (int i = 0; i < 2; i++) m_pads[i].m0 = func_00107270(src, i);
    m130 = 1;
}
