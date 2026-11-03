extern "C" void* func_001046B0(int size);
extern "C" void func_00105260(void* list, void* node);
extern "C" void func_001AA1D0(void);
extern char* D_0038C308;

struct TBase1AA150 {
    int m0[6];
    TBase1AA150(int id);
    virtual void Run();
};

struct Owner1AA150 {
    int m0;
    void* m4;
    Owner1AA150* Attach();
};

struct Task1AA150 : TBase1AA150 {
    void (*m1C)(void);
    Owner1AA150* m20;
    Task1AA150(void (*fn)(void), Owner1AA150* owner) : TBase1AA150(-0x44C) { m1C = fn; m20 = owner; }
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    virtual void Run();
};

Owner1AA150* Owner1AA150::Attach()
{
    Task1AA150* t = new Task1AA150(func_001AA1D0, this);
    m4 = t;
    func_00105260(D_0038C308 + 8, t);
    return this;
}
