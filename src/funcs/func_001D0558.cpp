struct Node_001D0558 {
    char m_pad0[0x20];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int Test(int arg);
};

extern "C" Node_001D0558* func_001D05B0(void* a, int b, int c);

extern "C" bool func_001D0558(void* a, int b, int arg, int c)
{
    Node_001D0558* n = func_001D05B0(a, b, c);
    if (n)
        return n->Test(arg) != 0;
    return false;
}
