/* sym: __13Base_001FB690 = 0x001FE410 */
/* sym: __17TaskBase_001FB690i = 0x001047F8 */
/* sym: _vt$12Obj_001FB690 = 0x003669A0 */
/* sym: _vt$13Task_001FB690 = 0x003669E0 */
extern "C" void func_001FE178(void* p);
extern "C" void* func_001046B0(int size);

struct TaskBase_001FB690 {
    char pad[0x18];
    TaskBase_001FB690(int pri);
    virtual void Run();
};

struct Task_001FB690 : public TaskBase_001FB690 {
    void (*m_func)(void*);
    void* m_data;
    Task_001FB690(void (*f)(void*), void* d) : TaskBase_001FB690(-2000)
    {
        m_func = f;
        m_data = d;
    }
    virtual void Run();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Base_001FB690 {
    char pad0[0x1840];
    Task_001FB690* m_task;
    char pad1844[0x4358 - 0x1844];
    Base_001FB690();
    virtual void Update();
};

struct Obj_001FB690 : public Base_001FB690 {
    Obj_001FB690();
    virtual void Update();
};

Obj_001FB690::Obj_001FB690()
{
    m_task = new Task_001FB690(func_001FE178, this);
}
