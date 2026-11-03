struct LNode_00200EF8 {
    int m0;
    int m_data;
    int m8;
    LNode_00200EF8* m_next;
    LNode_00200EF8* Next() {
        LNode_00200EF8* n = m_next;
        if (n->m_data == -1) {
            return 0;
        }
        return n;
    }
};

struct Iter_00200EF8 {
    int m0;
    LNode_00200EF8* m_cur;
};

struct List_00200EF8 {
    char pad0[0xF4];
    LNode_00200EF8 m_head;
    int Next(Iter_00200EF8* it);
};

int List_00200EF8::Next(Iter_00200EF8* it) {
    it->m_cur = it->m_cur->Next();
    if (it->m_cur) {
        return it->m_cur->m_data;
    }
    return 0;
}
