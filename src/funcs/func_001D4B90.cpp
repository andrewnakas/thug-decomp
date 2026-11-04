struct Obj_001D4B90 {
    int m_pad[3];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void Notify(int a, int b);
};

struct Node_001D4B90 {
    int m0;
    Obj_001D4B90* m_data;
    int m8;
    Node_001D4B90* m_next;

    Node_001D4B90* Next()
    {
        Node_001D4B90* n = m_next;
        if ((int)n->m_data != -1)
            return n;
        return 0;
    }
};

struct List_001D4B90 {
    int m0;
    int m4;
    int m8;
    Node_001D4B90* m_first;
};

struct Owner_001D4B90 {
    int m_pad[4];
    List_001D4B90* m_list;
    void NotifyAll(int a, int b);
};

void Owner_001D4B90::NotifyAll(int a, int b)
{
    Node_001D4B90* n = 0;
    Node_001D4B90* f = m_list->m_first;
    if ((int)f->m_data != -1)
        n = f;
    while (n) {
        n->m_data->Notify(a, b);
        n = n->Next();
    }
}
