extern "C" void* func_001046B0(int size);
extern "C" void func_00105260(void* list, void* node);
extern "C" void func_001A4E10(void);
extern char* D_0038C308;

struct TBase1A4D90 {
    int m0[6];
    TBase1A4D90(int id);
    virtual void Run();
};

struct Owner1A4D90 {
    int m0;
    void* m4;
    Owner1A4D90* Attach();
};

struct Task1A4D90 : TBase1A4D90 {
    void (*m1C)(void);
    Owner1A4D90* m20;
    Task1A4D90(void (*fn)(void), Owner1A4D90* owner) : TBase1A4D90(-0x44C) { m1C = fn; m20 = owner; }
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    virtual void Run();
};

Owner1A4D90* Owner1A4D90::Attach()
{
    Task1A4D90* t = new Task1A4D90(func_001A4E10, this);
    m4 = t;
    func_00105260(D_0038C308 + 8, t);
    return this;
}
