/* fuzzy: 73.5 */
extern char D_00371C78[];

struct LNode_002B5278 {
    int m0;
    void* m_data;
    int m8;
    LNode_002B5278* m_next;
    LNode_002B5278* Next() {
        LNode_002B5278* n = m_next;
        if (n->m_data == (void*)-1) {
            return 0;
        }
        return n;
    }
};

struct Iter_002B5278 {
    int m0;
    LNode_002B5278* m_cur;
    void* m8;
    Iter_002B5278() { m8 = D_00371C78; }
    ~Iter_002B5278() { m8 = D_00371C78; }
};

struct List_002B5278 {
    LNode_002B5278 m_head;
    void* First(Iter_002B5278* it) {
        it->m_cur = &m_head;
        it->m_cur = it->m_cur->Next();
        if (it->m_cur) {
            return it->m_cur->m_data;
        }
        return 0;
    }
    void* Next(Iter_002B5278* it) {
        it->m_cur = it->m_cur->Next();
        if (it->m_cur) {
            return it->m_cur->m_data;
        }
        return 0;
    }
};

extern void* D_00392068;
extern "C" void func_002A47D8(void* s, void* p);

struct Obj_002B5278 {
    char pad[0xB0];
    List_002B5278 m_list;
    void RemoveAll();
};

void Obj_002B5278::RemoveAll()
{
    Iter_002B5278 it;
    void* s = D_00392068;
    Iter_002B5278* pi = &it;
    void* p = m_list.First(&it);
    while (p) {
        void* next = m_list.Next(pi);
        func_002A47D8(s, p);
        p = next;
    }
}
