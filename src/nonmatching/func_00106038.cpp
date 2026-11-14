/* fuzzy: 87.0 */
/* blocked: remaining: gp address and stackSize swap $a3/$v1 (global-alloc order); 240 statement orders tried, directed search best 5 words. */
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
    void* entry = m_entry;
    int stackSize = m_stackSize;
    int prio = m_priority;
    void* stack = m_stack;
    ThreadParam_00106038 p;
    p.entry = entry;
    p.stack = stack;
    p.stackSize = stackSize;
    p.initPriority = prio;
    p.gpReg = D_0038F3F0;
    m_id = func_0031BAA0(&p);
    return this;
}
