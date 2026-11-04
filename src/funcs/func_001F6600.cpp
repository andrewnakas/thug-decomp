struct Entry_001F6600 {
    long m0;
    long m8;
    int m10;
    int m14;
};

struct Ctx_001F6600 {
    int m0;
    int m4;
    int m8;
    int m_pad[17];
    Entry_001F6600* m50;
    int m54;
    int m58;
    int m5C;
};

static inline int Ahead_001F6600(int from, int to, int size)
{
    return (from + size - to) % size;
}

extern "C" int func_001F6600(Ctx_001F6600* c, Entry_001F6600* e)
{
    int ok = 1;
    int i = (c->m5C - c->m58 + c->m54) % c->m54;
    int size = c->m8 << 11;
    if (c->m58 > 0) {
        while (ok) {
            Entry_001F6600* p = &c->m50[i];
            if (!p->m14 || !e->m14)
                break;
            if (Ahead_001F6600(p->m10, e->m10, size) < e->m14) {
                int n = e->m10 + e->m14 - p->m10;
                if (p->m14 < n)
                    n = p->m14;
                p->m10 = (p->m10 + n) % size;
                p->m14 -= n;
                if (p->m14 == 0) {
                    if (p->m0 >= 0) {
                        p->m0 = -1;
                        p->m8 = -1;
                        p->m10 = 0;
                        p->m14 = 0;
                    }
                    int k = c->m58 - 1;
                    if (k < 0)
                        k = 0;
                    c->m58 = k;
                }
            } else {
                ok = 0;
            }
            i = (i + 1) % c->m54;
        }
    }
    return 0;
}
