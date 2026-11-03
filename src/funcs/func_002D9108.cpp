struct Heap_002D9108 {
    char pad0[0xF4];
    void* mF4;
};

extern Heap_002D9108* D_00388A70;
extern "C" void func_0010A950(void* h, void* ctx);
extern "C" void func_0010A9B0(void* h);
extern "C" void* func_001046B0(unsigned int size);
extern "C" void func_002D8F00(void* p);

struct Link_002D9108 {
    unsigned int m0;
    unsigned int m4;
    int m8;
    Link_002D9108* m_next;
    Link_002D9108* m_prev;
    Link_002D9108()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        m_next = this;
        m_prev = this;
    }
    virtual void Key();
    virtual ~Link_002D9108();
};

struct NodeA_002D9108 : public Link_002D9108 {
    NodeA_002D9108() {}
    virtual void Key();
};

struct NodeB_002D9108 : public Link_002D9108 {
    NodeB_002D9108() {}
    virtual void Key();
};

struct Elem_002D9108 {
    NodeA_002D9108 m0;
    NodeB_002D9108 m18;
    char pad30[0x20];
};

struct Mem_002D9108 {
    char pad[0x68];
    Mem_002D9108();
};

struct Task_002D9108 {
    char pad0[0x18];
    Task_002D9108(int v);
    virtual void Run();
};

struct Cb_002D9108 : public Task_002D9108 {
    void (*m1C)(void*);
    void* m20;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb_002D9108(void (*f)(void*), void* p) : Task_002D9108(0)
    {
        m1C = f;
        m20 = p;
    }
    virtual void Run();
};

struct Obj_002D9108 {
    Cb_002D9108* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Mem_002D9108 m14;
    Elem_002D9108 m7C[5];
    int m20C;
    Obj_002D9108();
};

Obj_002D9108::Obj_002D9108()
{
    func_0010A950(D_00388A70, D_00388A70->mF4);
    m0 = new Cb_002D9108(func_002D8F00, this);
    m4 = 0;
    m8 = 0;
    mC = 0;
    m20C = 1;
    func_0010A9B0(D_00388A70);
}
