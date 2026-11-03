struct LNode_002A5520 {
    int m0;
    int m_data;
    int m8;
    LNode_002A5520* m_next;
    LNode_002A5520* Next() {
        LNode_002A5520* n = m_next;
        if (n->m_data == -1) {
            return 0;
        }
        return n;
    }
};

struct Iter_002A5520 {
    int m0;
    LNode_002A5520* m_cur;
};

struct List_002A5520 {
    char pad0[0xF4];
    LNode_002A5520 m_head;
    int Next(Iter_002A5520* it);
};

int List_002A5520::Next(Iter_002A5520* it) {
    it->m_cur = it->m_cur->Next();
    if (it->m_cur) {
        return it->m_cur->m_data;
    }
    return 0;
}
