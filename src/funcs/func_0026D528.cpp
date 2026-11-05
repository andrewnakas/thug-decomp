struct N_0026D528 {
    int m0;
    int m4;
    int m8;
    N_0026D528* mC;
    N_0026D528* Valid() { if (m4 == -1) return 0; return this; }
};

struct C_0026D528 {
    char m_pad[0x10];
    N_0026D528* m10;
    int Count();
};

int C_0026D528::Count()
{
    int n = 0;
    N_0026D528* p = m10;
    N_0026D528* q;
    while ((q = p->Valid()) != 0) {
        p = q->mC;
        n++;
    }
    return n;
}
