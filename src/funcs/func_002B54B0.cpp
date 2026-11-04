extern char D_00371C78[];

struct Sub_002B54B0 {
    int m0;
};

struct Item_002B54B0 {
    char pad[0x34];
    Sub_002B54B0 m34;
};

struct LNode_002B54B0 {
    int m0;
    Item_002B54B0* m_data;
    int m8;
    LNode_002B54B0* m_next;
    Item_002B54B0* Data() { return m_data; }
    LNode_002B54B0* Next() {
        LNode_002B54B0* n = m_next;
        if (n->m_data == (Item_002B54B0*)-1) {
            return 0;
        }
        return n;
    }
};

struct Iter_002B54B0 {
    int m0;
    LNode_002B54B0* m_cur;
    void* m8;
    Iter_002B54B0() { m8 = D_00371C78; }
    ~Iter_002B54B0() { m8 = D_00371C78; }
};

struct List_002B54B0 {
    LNode_002B54B0 m_head;
    Item_002B54B0* First(Iter_002B54B0* it) {
        it->m_cur = &m_head;
        it->m_cur = it->m_cur->Next();
        if (!it->m_cur) {
            return 0;
        }
        return it->m_cur->m_data;
    }
    Item_002B54B0* Next(Iter_002B54B0* it) {
        it->m_cur = it->m_cur->Next();
        if (!it->m_cur) {
            return 0;
        }
        return it->m_cur->Data();
    }
};

struct Obj_002B54B0 {
    char pad[0xB0];
    List_002B54B0 m_list;
    Sub_002B54B0* GetNth(int n);
};

Sub_002B54B0* Obj_002B54B0::GetNth(int n)
{
    Iter_002B54B0 it;
    for (Item_002B54B0* p = m_list.First(&it); p; p = m_list.Next(&it)) {
        if (n == 0)
            return &p->m34;
        n--;
    }
    return 0;
}
