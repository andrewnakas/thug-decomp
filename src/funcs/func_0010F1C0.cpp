/* sym: __13Base_0010F1C0 = 0x001829A8 */
/* sym: __13Task_0010F1C0i = 0x001047F8 */
/* sym: _vt$12Obj_0010F1C0 = 0x0035BAC8 */
/* sym: _vt$11Cb_0010F1C0 = 0x0035BAF0 */
extern "C" void* func_001046B0(int size);
extern "C" void func_0010F2F0(void* owner);

class Base_0010F1C0 {
public:
    char pad[0x14];
    Base_0010F1C0();
    virtual ~Base_0010F1C0();
};

class Task_0010F1C0 {
public:
    int m0;
    int m4;
    void* m8;
    int mC;
    int m10;
    int m14;
    Task_0010F1C0(int data);
    virtual void Func1() = 0;
    virtual void Func2() = 0;
    virtual ~Task_0010F1C0();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Cb_0010F1C0 : public Task_0010F1C0 {
public:
    void (*m_fn)(void*);
    void* m_owner;
    Cb_0010F1C0(void (*fn)(void*), void* owner) : Task_0010F1C0(0)
    {
        m_fn = fn;
        m_owner = owner;
    }
    virtual void Func1();
    virtual void Func2();
};

class Obj_0010F1C0 : public Base_0010F1C0 {
public:
    Cb_0010F1C0* m_task;
    Obj_0010F1C0();
    virtual void Run();
};

Obj_0010F1C0::Obj_0010F1C0()
{
    m_task = new Cb_0010F1C0(func_0010F2F0, this);
}
