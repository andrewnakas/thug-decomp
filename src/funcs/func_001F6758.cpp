extern "C" int func_0031BCE0(int);
extern "C" void func_0031BCC0(int);

struct Entry_001F6758 {
    long m0;
    long m8;
    int m10;
    int m14;
};

struct Ctx_001F6758;
extern "C" int func_001F6600(Ctx_001F6758*, Entry_001F6758*);

struct Ctx_001F6758 {
    int m_pad[16];
    int m40;
    int m_pad2[3];
    Entry_001F6758* m50;
    int m54;
    int m58;
    int m5C;
};

int func_001F6758(Ctx_001F6758* c, Entry_001F6758* e)
{
    int ret = 0;
    func_0031BCE0(c->m40);
    if (c->m58 < c->m54) {
        func_001F6600(c, e);
        if (e->m0 >= 0 || e->m8 >= 0) {
            c->m50[c->m5C].m0 = e->m0;
            c->m50[c->m5C].m8 = e->m8;
            c->m50[c->m5C].m10 = e->m10;
            c->m50[c->m5C].m14 = e->m14;
            c->m58 = c->m58 + 1;
            c->m5C = (c->m5C + 1) % c->m54;
        }
        ret = 1;
    }
    func_0031BCC0(c->m40);
    return ret;
}
