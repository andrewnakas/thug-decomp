struct Obj_001D47E0 {
    int m_pad[3];
    virtual void V0();
    virtual int Check();
};

struct Node_001D47E0 {
    int m0;
    Obj_001D47E0* m_data;
    int m8;
    Node_001D47E0* m_next;

    Node_001D47E0* Next()
    {
        Node_001D47E0* n = m_next;
        if ((int)n->m_data != -1)
            return n;
        return 0;
    }
};

struct List_001D47E0 {
    int m0;
    int m4;
    int m8;
    Node_001D47E0* m_first;

    Node_001D47E0* First()
    {
        Node_001D47E0* f = m_first;
        if ((int)f->m_data != -1)
            return f;
        return 0;
    }
};

struct Owner_001D47E0 {
    int m_pad[4];
    List_001D47E0* m_list;
    bool CheckAll();
};

bool Owner_001D47E0::CheckAll()
{
    bool ok = true;
    for (Node_001D47E0* n = m_list->First(); n; n = n->Next())
        ok = ok && n->m_data->Check();
    return ok;
}
