/* fuzzy: 96.7 */
/* blocked: 6 words: the m5C load is scheduled before the divu and pos lands in $s0 instead of $v1; statement
   orders tried, directed search: no match. */
extern "C" int func_0031BCE0(int);
extern "C" void func_0031BCC0(int);

#define REG_001F6868(a) (*(volatile unsigned int*)(a))

struct Entry_001F6868 {
    long m0;
    long m8;
    int m10;
    int m14;
};

struct Ctx_001F6868 {
    unsigned int m0;
    int m4;
    int m8;
    int m_pad[11];
    int m38;
    int m3C;
    int m40;
    int m_pad2[3];
    Entry_001F6868* m50;
    int m54;
    int m58;
    int m5C;
};

static inline int Ahead_001F6868(int from, int to, int size)
{
    return (from + size - to) % size;
}

int func_001F6868(Ctx_001F6868* c, Entry_001F6868* e)
{
    int found = 0;
    unsigned int addr = REG_001F6868(0x1000B410);
    unsigned int v = REG_001F6868(0x10002020);
    int bits = c->m38 & 0x7F;
    int size = c->m8 << 11;
    addr -= (((v >> 16) & 3) + ((v >> 8) & 0xF)) * 16;
    func_0031BCE0(c->m40);
    e->m0 = -1;
    e->m8 = -1;
    unsigned int pos = (addr + (bits >> 3) + size - c->m0) % size;
    int count = c->m58;
    int start = c->m5C - count;
    for (int j = 0; j < count && !found; j++) {
        int idx = (start + c->m54 + j) % c->m54;
        if (Ahead_001F6868(pos, c->m50[idx].m10, size) < c->m50[idx].m14) {
            found = 1;
            e->m0 = c->m50[idx].m0;
            e->m8 = c->m50[idx].m8;
            c->m50[idx].m0 = -1;
            c->m50[idx].m8 = -1;
            int dec = c->m58;
            int k = dec;
            if (dec > 1)
                dec = 1;
            c->m58 = k - dec;
        }
    }
    func_0031BCC0(c->m40);
    return 1;
}
