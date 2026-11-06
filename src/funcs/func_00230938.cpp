/* sym: __13Base_00230938i = 0x001047F8 */
/* sym: _vt$13Task_00230938 = 0x00373070 */
extern "C" void* func_001046B0(int size);
extern "C" void func_00231188(void* t);
extern "C" void func_00231728(void* t);

struct Owner_00230938;

struct Base_00230938 {
    int m_pad[6];
    Base_00230938(int pri);
    virtual void Run();
};

struct Task_00230938 : Base_00230938 {
    void (*m_func)(void*);
    Owner_00230938* m_owner;
    Task_00230938(void (*fn)(void*), Owner_00230938* o) : Base_00230938(-1000), m_func(fn), m_owner(o) {}
    virtual void Run();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Owner_00230938 {
    char pad[0x1C];
    Task_00230938* m_task0;
    Task_00230938* m_task1;
    void Init();
};

void Owner_00230938::Init()
{
    m_task0 = new Task_00230938(func_00231188, this);
    m_task1 = new Task_00230938(func_00231728, this);
}
