struct Ent_001DCFB0 {
    int m_a;
    int m_b;
    int m_used;
    int m_c;
    Ent_001DCFB0* m_next;
    Ent_001DCFB0* m_prev;
};

extern int D_0038E0B8;
extern Ent_001DCFB0* D_0038E0AC;
extern Ent_001DCFB0 D_003ECCD0[128];

struct Obj_001DCFB0 {
    void Add(int a, int b, int c);
};

void Obj_001DCFB0::Add(int a, int b, int c)
{
    if (!a)
        return;
    if (D_0038E0B8 == 128)
        return;
    D_0038E0B8++;
    Ent_001DCFB0* head = D_0038E0AC;
    int i = 0;
    do {
        Ent_001DCFB0* p = &D_003ECCD0[i];
        if (!(p->m_used & 1)) {
            if (head)
                head->m_prev = p;
            p->m_next = head;
            p->m_prev = 0;
            head = p;
            head->m_a = a;
            head->m_b = b;
            head->m_used = 1;
            head->m_c = c;
            break;
        }
        i++;
    } while (i < 128);
    D_0038E0AC = head;
}
