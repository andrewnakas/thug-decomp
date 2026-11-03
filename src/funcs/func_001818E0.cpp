extern "C" void func_0010BEB8(void* p);

struct T_001818E0;

struct N_001818E0 {
    N_001818E0* m_next;
    char pad4[0x48 - 0x4];
    T_001818E0* m_owner;
    N_001818E0* m_prev;
};

struct T_001818E0 {
    char pad0[0x1C];
    void* m1C;
    void* m20;
    void* m24;
    char pad28[0x40 - 0x28];
    T_001818E0* m_next;
};

extern N_001818E0* D_003942F4;
extern N_001818E0* D_003942F8;
extern T_001818E0* D_00394310;

void Destroy_001818E0(T_001818E0* t)
{
    func_0010BEB8(t->m1C);
    func_0010BEB8(t->m20);
    if (t->m24) func_0010BEB8(t->m24);
    N_001818E0* n = D_003942F4;
    while (n) {
        if (n->m_owner == t) {
            if (n == D_003942F4) {
                n->m_next->m_prev = 0;
                D_003942F4 = n->m_next;
            } else if (n == D_003942F8) {
                n->m_prev->m_next = 0;
                D_003942F8 = n->m_prev;
            } else {
                n->m_next->m_prev = n->m_prev;
                n->m_prev->m_next = n->m_next;
            }
            N_001818E0* d = n;
            n = n->m_next;
            func_0010BEB8(d);
        } else {
            n = n->m_next;
        }
    }
    if (t == D_00394310) {
        D_00394310 = t->m_next;
    } else {
        T_001818E0* p = D_00394310;
        while (p && p->m_next != t) p = p->m_next;
        p->m_next = t->m_next;
    }
    func_0010BEB8(t);
}
