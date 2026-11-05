struct Node_0013AEB8 {
    int m0[4];
    Node_0013AEB8* m_next;
    void Push();
};

extern Node_0013AEB8* D_0038A07C;

void Node_0013AEB8::Push()
{
    m_next = D_0038A07C;
    D_0038A07C = this;
}
