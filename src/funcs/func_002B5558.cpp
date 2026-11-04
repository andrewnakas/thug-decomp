extern char D_00371C78[];

struct Item_002B5558 {
    char pad[0x2C];
    int m2C;
};

struct LNode_002B5558 {
    int m0;
    Item_002B5558* m_data;
    int m8;
    LNode_002B5558* m_next;
    Item_002B5558* Data() { return m_data; }
    LNode_002B5558* Next() {
        LNode_002B5558* n = m_next;
        if (n->m_data == (Item_002B5558*)-1) {
            return 0;
        }
        return n;
    }
};

struct Iter_002B5558 {
    int m0;
    LNode_002B5558* m_cur;
    void* m8;
    Iter_002B5558() { m8 = D_00371C78; }
    ~Iter_002B5558() { m8 = D_00371C78; }
};

struct List_002B5558 {
    LNode_002B5558 m_head;
    Item_002B5558* First(Iter_002B5558* it) {
        it->m_cur = &m_head;
        it->m_cur = it->m_cur->Next();
        if (!it->m_cur) {
            return 0;
        }
        return it->m_cur->m_data;
    }
    Item_002B5558* Next(Iter_002B5558* it) {
        it->m_cur = it->m_cur->Next();
        if (!it->m_cur) {
            return 0;
        }
        return it->m_cur->Data();
    }
};

struct Obj_002B5558 {
    char pad[0xB0];
    List_002B5558 m_list;
    int GetNth(int n);
};

int Obj_002B5558::GetNth(int n)
{
    Iter_002B5558 it;
    for (Item_002B5558* p = m_list.First(&it); p; p = m_list.Next(&it)) {
        if (n == 0)
            return p->m2C;
        n--;
    }
    return 0;
}
