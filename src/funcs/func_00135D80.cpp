struct Node_00135D80 {
    int m0[13];
    Node_00135D80* m_next;
};

extern Node_00135D80* D_00389DB0;

Node_00135D80* Pop_00135D80()
{
    Node_00135D80* n = D_00389DB0;
    if (n)
        D_00389DB0 = n->m_next;
    return n;
}
