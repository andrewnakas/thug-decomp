struct NodeBase {
    int m_data[6];
};

struct Task_00270A10 : NodeBase {
    virtual void V0();
    virtual void V1();
    virtual void V2(int arg);
    void Run(int arg);
};

void Task_00270A10::Run(int arg)
{
    V2(arg);
}
