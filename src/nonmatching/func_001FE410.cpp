/* fuzzy: 98.2 */
/* sym: __17TaskBase_001FE410i = 0x001047F8 */
/* sym: _vt$12Net_001FE410 = 0x00366B70 */
/* sym: _vt$13Slot_001FE410 = 0x00366C50 */
/* sym: _vt$13Head_001FE410 = 0x003668A0 */
/* sym: _vt$14ListA_001FE410 = 0x00366BC8 */
/* sym: _vt$14ListB_001FE410 = 0x00366BB0 */
/* sym: _vt$13Task_001FE410 = 0x003669E0 */
extern "C" void* func_001046B0(int size);
extern "C" void func_001FE018();
extern "C" void func_001FDFA8();
extern "C" void func_001FE0B0();

class TaskBase_001FE410 {
public:
    char pad0[0x18];
    TaskBase_001FE410(int pri);
    virtual ~TaskBase_001FE410();
};

class Task_001FE410 : public TaskBase_001FE410 {
public:
    Task_001FE410(void* code, void* data, int pri)
        : TaskBase_001FE410(pri)
    {
        m_code = code;
        m_data = data;
    }
    virtual void Vfn();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    void* m_code;
    void* m_data;
};

class SlotBase_001FE410 {
public:
    int m0;
    unsigned int m_pri;
    int m8;
    SlotBase_001FE410* m_prev;
    SlotBase_001FE410* m_next;
    SlotBase_001FE410()
    {
        m_pri = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
};

class Slot_001FE410 : public SlotBase_001FE410 {
public:
    virtual void Vfn();
};

class Head_001FE410 {
public:
    int m0;
    void* m_data;
    int m8;
    Head_001FE410* m_prev;
    Head_001FE410* m_next;
    Head_001FE410(void* data)
    {
        m_data = data;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
    virtual void Vfn();
};

class ListA_001FE410 {
public:
    int m0;
    unsigned int m_pri;
    int m8;
    ListA_001FE410* m_prev;
    ListA_001FE410* m_next;
    ListA_001FE410()
    {
        m_pri = 0xFFFFFFFF;
        m_prev = this;
        m_next = this;
        m8 = 0;
    }
    virtual void Vfn();
};

class ListB_001FE410 {
public:
    int m0;
    unsigned int m_pri;
    int m8;
    ListB_001FE410* m_prev;
    ListB_001FE410* m_next;
    ListB_001FE410()
    {
        m_pri = 0xFFFFFFFF;
        m_prev = this;
        m_next = this;
        m8 = 0;
    }
    virtual void Vfn();
};

class Net_001FE410;

class Pool_001FE410 {
public:
    Slot_001FE410 m_slots[255];
    Net_001FE410* m_owner;
    Pool_001FE410(Net_001FE410* owner)
        : m_owner(owner)
    {
    }
};

class Net_001FE410 {
public:
    int m0;
    Pool_001FE410 m_pool;
    char pad17F0[0x1808 - 0x17F0];
    Head_001FE410 m_head;
    char pad1824[0x183C - 0x1820];
    Task_001FE410* m_task_c;
    char pad1840[4];
    Task_001FE410* m_task_b;
    Task_001FE410* m_task_a;
    char pad184C[0x227C - 0x184C];
    unsigned int m_flags;
    int m2280;
    char pad2284[0x42D8 - 0x2284];
    ListA_001FE410 m_list_a;
    ListB_001FE410 m_list_b;
    char pad4308[0x4350 - 0x4308];
    long m4350;
    Net_001FE410(int flags);
    void SetFlags(const unsigned int& f) { m_flags = f; }
    virtual void Vfn();
};

Net_001FE410::Net_001FE410(int flags)
    : m_pool(this), m_head(this), m_flags(0)
{
    m_task_a = new Task_001FE410((void*)func_001FE018, this, -2500);
    m_task_b = new Task_001FE410((void*)func_001FDFA8, this, 1000);
    m_task_c = new Task_001FE410((void*)func_001FE0B0, this, 0);
    m4350 = 0;
    SetFlags(flags);
    m0 = 0;
    m2280 = 0;
}
