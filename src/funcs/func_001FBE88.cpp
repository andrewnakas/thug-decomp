/* sym: __13Base_001FBE88 = 0x001FE410 */
/* sym: __17TaskBase_001FBE88i = 0x001047F8 */
/* sym: _vt$13Task_001FBE88 = 0x003669E0 */
/* sym: _vt$12Obj_001FBE88 = 0x00366A08 */

extern "C" void* func_001046B0(unsigned int size);
extern "C" void func_001FE178();

class TaskBase_001FBE88 {
public:
    char m_pad0[0x18];
    TaskBase_001FBE88(int pri);
    virtual ~TaskBase_001FBE88();
};

class Task_001FBE88 : public TaskBase_001FBE88 {
public:
    Task_001FBE88(void* code, void* data, int pri) : TaskBase_001FBE88(pri)
    {
        m_code = code;
        m_data = data;
    }
    virtual void Vfn();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    void* m_code;
    void* m_data;
};

class Base_001FBE88 {
public:
    char m_pad0[0x1840];
    Task_001FBE88* m_task;
    char m_pad1844[0x4358 - 0x1844];
    Base_001FBE88();
    virtual void Vfn();
};

class Obj_001FBE88 : public Base_001FBE88 {
public:
    Obj_001FBE88();
    virtual void Vfn();
};

Obj_001FBE88::Obj_001FBE88()
{
    m_task = new Task_001FBE88((void*)func_001FE178, this, -2000);
}
