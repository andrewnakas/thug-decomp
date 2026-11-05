extern "C" void func_00135A98(void* self, int v);
extern "C" void func_00135B78(void* self);

struct Node_00135DA0 {
    int m0[13];
    Node_00135DA0* m_next;
    void Release();
};

extern Node_00135DA0* D_00389DB0;

void Node_00135DA0::Release()
{
    func_00135A98(this, 1);
    func_00135B78(this);
    m_next = D_00389DB0;
    D_00389DB0 = this;
}
