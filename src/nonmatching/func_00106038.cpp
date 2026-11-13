/* fuzzy: 78.3 */
struct ThreadParam_00106038 {
    int status;
    void* entry;
    void* stack;
    int stackSize;
    void* gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
};

extern char D_0038F3F0[];
extern "C" int func_0031BAA0(ThreadParam_00106038* p);

struct Thread_00106038 {
    char pad0[0x14];
    int m_id;
    void* m_entry;
    void* m_stack;
    int m_stackSize;
    int m_priority;
    Thread_00106038* Create();
};

Thread_00106038* Thread_00106038::Create()
{
    ThreadParam_00106038 p;
    p.entry = m_entry;
    p.stackSize = m_stackSize;
    p.gpReg = D_0038F3F0;
    p.initPriority = m_priority;
    p.stack = m_stack;
    m_id = func_0031BAA0(&p);
    return this;
}
