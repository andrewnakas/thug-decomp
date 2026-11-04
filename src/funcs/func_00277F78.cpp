struct NodeBase {
    int m_data[6];
};

struct Task_00277F78 : NodeBase {
    virtual void V0();
    virtual void V1();
    virtual void V2(int arg);
    void Run(int arg);
};

void Task_00277F78::Run(int arg)
{
    V2(arg);
}
