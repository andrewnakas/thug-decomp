extern "C" void* func_001046B0(int size);

struct Stage_00255278 {
    int m_flags;
    char m_list[0x50 - 0x4];
    char m_stamp[0x94 - 0x50];
};

struct Sched_00255278 {
    char pad0[0x8];
    Stage_00255278 m_stages[4];
};

class TaskBase_00255278 {
public:
    char pad0[0x18];
    TaskBase_00255278(int a);
    virtual ~TaskBase_00255278();
};

class Task_00255278 : public TaskBase_00255278 {
public:
    Task_00255278(void* code, void* data, int stage)
        : TaskBase_00255278(0)
    {
        m_code = code;
        m_stage = stage;
        m_data = data;
    }
    virtual void Vfn();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    void* m_stamp;
    int m_flags;
    int m_stage;
    void* m_code;
    void* m_data;
};

struct Handlers_00255278 {
    int m0;
    char m_list[4];
};

class Base_00255278 {
public:
    char pad0[0x8];
    Base_00255278();
    virtual ~Base_00255278();
};

class Obj_00255278 : public Base_00255278 {
public:
    Obj_00255278(Handlers_00255278* handlers);
    virtual void Vfn();
    char pad0C[0x70 - 0xC];
    float m_matrix[16];
    char padB0[0x160 - 0xB0];
    Task_00255278* m_task;
    char pad164[0x168 - 0x164];
    int m168;
    Handlers_00255278* m_handlers;
    float m_speed;
    int m174;
    int m178;
};

extern "C" void func_00105260(void* list, Task_00255278* task);
extern "C" void func_001FBF60(char* list, int type, void* handler, int a, Obj_00255278* obj, int b);
extern "C" void func_00256468();
extern "C" void func_002550A0();
extern "C" void func_002550C8();
extern "C" void func_002550F0();
extern "C" void func_00255118();
extern "C" void func_002551F8();
extern "C" void func_00255140();

extern Sched_00255278* D_0038C3C0;


Obj_00255278::Obj_00255278(Handlers_00255278* handlers)
    : m168(0)
{
    Sched_00255278* sched = D_0038C3C0;
    Task_00255278* task = new Task_00255278((void*)func_00256468, this, 0);
    m_task = task;
    func_00105260(sched->m_stages[task->m_stage].m_list, task);
    task->m_stamp = sched->m_stages[task->m_stage].m_stamp;
    task->m_flags = sched->m_stages[task->m_stage].m_flags;
    m178 = 1;
    m_speed = 1.0f;
    float* m = m_matrix;
    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 1.0f;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
    m_handlers = handlers;
    m174 = 0;
    func_001FBF60(handlers->m_list, 0x25, (void*)func_002550A0, 3, this, 0x80);
    func_001FBF60(m_handlers->m_list, 0x26, (void*)func_002550C8, 3, this, 0x80);
    func_001FBF60(m_handlers->m_list, 0x27, (void*)func_002550F0, 3, this, 0x80);
    func_001FBF60(m_handlers->m_list, 0x28, (void*)func_00255118, 3, this, 0x80);
    func_001FBF60(m_handlers->m_list, 0x29, (void*)func_002551F8, 3, this, 0x80);
    func_001FBF60(m_handlers->m_list, 0x2C, (void*)func_00255140, 3, this, 0x80);
}
