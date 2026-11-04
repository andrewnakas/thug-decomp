struct Item_0016D828 {
    Item_0016D828* m_next;
    int m4;
    int m_id;
};

struct Ent_0016D828 {
    int m0;
    int m4;
    char pad[0x40];
};

struct Tab_0016D828 {
    char pad[0x18];
    int m_count;
    char pad1c[8];
    Ent_0016D828* m_ents;
};

struct Own_0016D828 {
    char pad[8];
    int m8;
    char padc[0x3C];
    Tab_0016D828* m48;
};

struct Node_0016D828 {
    char pad[0x18];
    unsigned long m18;
    union {
        Node_0016D828* m_children;
        void* m_data;
    };
    int m24;
    Node_0016D828* m28;
    int m2C;
    int pad30;
    int m34;
    int* m38;
    int pad3c[2];
    Ent_0016D828* m44;
    int pad48;
    Node_0016D828* m4C;
};

extern Item_0016D828* D_003942F4;
extern "C" Own_0016D828* func_00170728(Node_0016D828* self);

extern "C" int func_0016D828(Node_0016D828* n, int base)
{
    int count = 0;
    if (!(((int*)n)[7] & 2)) {
        count = 1;
        if (n->m24 != -1)
            n->m24 = base + n->m24;
        else
            n->m24 = 0;
    }
    Ent_0016D828* want = n->m44;
    n->m44 = 0;
    if (((int*)n)[7] & 2) {
        if (n->m_data) {
            Item_0016D828* it = D_003942F4;
            while (it && it->m_id != n->m2C)
                it = it->m_next;
            n->m2C = (int)it;
            if (want) {
                Tab_0016D828* t = func_00170728(n)->m48;
                int num = t->m_count;
                Ent_0016D828* e = t->m_ents;
                for (int i = 0; i < num; i++) {
                    if (e->m0 == (int)want && e->m4 == func_00170728(n)->m8) {
                        n->m44 = e;
                        break;
                    }
                    e++;
                }
            }
        }
    }
    if (((int*)n)[7] & 2) {
        if ((int)n->m_data != -1)
            n->m_data = (void*)(base + (int)n->m_data);
        else
            n->m_data = 0;
    } else {
        if ((int)n->m_children != -1)
            n->m_children = (Node_0016D828*)(base + (int)n->m_children);
        else
            n->m_children = 0;
    }
    if ((int)n->m28 != -1)
        n->m28 = (Node_0016D828*)(base + (int)n->m28);
    else
        n->m28 = 0;
    if ((int)n->m4C != -1)
        n->m4C = (Node_0016D828*)(base + (int)n->m4C);
    else
        n->m4C = 0;
    unsigned int flags = ((unsigned int*)n)[7];
    if (flags & 0x200) {
        unsigned long mask = 0x400200000000UL;
        if ((n->m18 & mask) != mask) {
            n->m34 = base + n->m34;
        } else {
            n->m34 = 0;
            ((unsigned int*)n)[7] = flags & ~0x200;
        }
    }
    if ((int)n->m38 != -1) {
        n->m38 = (int*)(base + (int)n->m38);
        int* p = n->m38;
        int groups = *p++;
        for (int i = 0; i < groups; i++) {
            *p = base + *p;
            p++;
            int k = *p++;
            for (int j = 0; j < k; j++) {
                *p = base + *p;
                p++;
            }
        }
    } else {
        n->m38 = 0;
    }
    if (!(((int*)n)[7] & 2)) {
        for (Node_0016D828* c = n->m_children; c; c = c->m28)
            count += func_0016D828(c, base);
    }
    if (n->m4C)
        func_0016D828(n->m4C, base);
    return count;
}
