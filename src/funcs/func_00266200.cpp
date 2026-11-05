struct P_00266200 {
    int m0;
    unsigned char m4;
    int m8;
};

struct C_00266200 {
    char m_pad[0x18];
    int m18;
    void Tick(P_00266200* p);
};

void C_00266200::Tick(P_00266200* p)
{
    if (p->m8 == 0) {
        if (p->m4 == 0) {
            p->m8 = 1;
            p->m0 = m18;
        } else {
            p->m4--;
        }
    }
}
