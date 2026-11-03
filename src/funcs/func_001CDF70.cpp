/* cflags: -fopt-stack */
struct NodeBase {
    int m_data[6];
};

struct TaskBase : NodeBase {
    virtual void V0();
    virtual void V1();
};

struct Task : TaskBase {
    int m1C;
    int m20;
    int m_busy;
    void RunGuarded();
};

void Task::RunGuarded()
{
    m_busy = 1;
    V1();
    m_busy = 0;
}
