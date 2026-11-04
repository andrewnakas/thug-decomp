struct NodeBase {
    int m_data[6];
};

struct Task1B76E8 : NodeBase {
    virtual void V0();
    virtual void V1();
    virtual void V2(int arg);
    void Run(int arg);
};

void Task1B76E8::Run(int arg)
{
    V2(arg);
}
