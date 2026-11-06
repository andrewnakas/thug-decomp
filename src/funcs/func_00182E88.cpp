struct Node_00182E88 {
    int m0[2];
    int m_8;
    int m_C;
};

struct Obj_00182E88 {
    int m0[8];
    int m_20;
    void Mark(Node_00182E88* n);
};

void Obj_00182E88::Mark(Node_00182E88* n)
{
    if (!n->m_C) {
        n->m_8 = 1;
        m_20 = 1;
    }
}
