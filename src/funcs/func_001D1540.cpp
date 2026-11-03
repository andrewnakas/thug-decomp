struct Obj_001D1540 {
    int m_pad[8];
    virtual void V0();
    virtual int V1(int a, int b, int c, int d, int e);
    virtual void V2();
    virtual int V3();
    bool Run(int a);
};

bool Obj_001D1540::Run(int a)
{
    V3();
    return V1(a, 0, 0, 0, 0) == 0;
}
