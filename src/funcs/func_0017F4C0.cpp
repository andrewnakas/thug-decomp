struct Prim_0017F4C0 {
    int m0;
    int m4;
    float m_pri;
    unsigned int mC;
    int* m10;
    Prim_0017F4C0* m_next;
};

extern "C" void func_0017F4C0(Prim_0017F4C0* p, Prim_0017F4C0** head)
{
    Prim_0017F4C0* first = *head;
    if (!first || p->m_pri <= first->m_pri) {
        p->m_next = first;
        *head = p;
        return;
    }
    Prim_0017F4C0* cur = first;
    while (cur->m_next) {
        if (p->m_pri <= cur->m_next->m_pri) {
            break;
        }
        cur = cur->m_next;
    }
    p->m_next = cur->m_next;
    cur->m_next = p;
}
