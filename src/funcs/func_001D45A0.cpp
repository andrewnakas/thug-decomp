struct Obj_001D45A0 {
    int m_pad[3];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Notify(int a);
};

struct Node_001D45A0 {
    int m0;
    Obj_001D45A0* m_data;
    int m8;
    Node_001D45A0* m_next;

    Node_001D45A0* Next()
    {
        Node_001D45A0* n = m_next;
        if ((int)n->m_data != -1)
            return n;
        return 0;
    }
};

struct List_001D45A0 {
    int m0;
    int m4;
    int m8;
    Node_001D45A0* m_first;
};

struct Owner_001D45A0 {
    int m_pad[4];
    List_001D45A0* m_list;
    int m_pad2[11];
    int m_dirty;
    void NotifyAll(int a);
};

void Owner_001D45A0::NotifyAll(int a)
{
    Node_001D45A0* n = 0;
    Node_001D45A0* f = m_list->m_first;
    if ((int)f->m_data != -1)
        n = f;
    while (n) {
        n->m_data->Notify(a);
        n = n->Next();
    }
    m_dirty = 1;
}
