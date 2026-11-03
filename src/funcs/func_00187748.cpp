inline void* operator new(unsigned int, void* p) { return p; }
extern char* D_0038C308;
extern "C" void* func_001046B0(int size);
extern "C" void func_00105260(void* list, void* node);
extern "C" void func_00187440();

struct TB_00187748 {
    char pad[0x18];
    TB_00187748(int priority);
    virtual void V0();
};

struct Task_00187748 : TB_00187748 {
    void* m_func;
    void* m_owner;
    Task_00187748(void* f, void* owner) : TB_00187748(1000) { m_func = f; m_owner = owner; }
    virtual void V0();
};

struct N_00187748 {
    int m0;
    unsigned int m_data;
    int m_pri;
    N_00187748* m_next;
    N_00187748* m_prev;
    N_00187748()
    {
        m_data = 0xFFFFFFFF;
        m_next = this;
        m_prev = this;
        m_pri = 0;
    }
    virtual void V0();
};

struct B_00187748 {
    char pad[0x2C];
    B_00187748();
    virtual void V0();
};

struct C_00187748 : B_00187748 {
    N_00187748 m_list;
    Task_00187748* m_task;
    C_00187748();
    virtual void V0();
};

C_00187748::C_00187748()
{
    m_task = new (func_001046B0(0x24)) Task_00187748((void*)func_00187440, this);
    func_00105260(D_0038C308 + 0xA0, m_task);
}
