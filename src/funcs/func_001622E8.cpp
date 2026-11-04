union Code_001622E8 {
    struct {
        unsigned short h0;
        unsigned short h2;
        unsigned int w4;
        unsigned int w8;
    } s;
    unsigned char b[4];
};

extern int D_003942DC;
extern unsigned int D_003942E0;
extern "C" Code_001622E8* func_00164D20(Code_001622E8* c);

extern "C" void func_001622E8(Code_001622E8* pkt)
{
    Code_001622E8* marks[5];
    Code_001622E8* c = (Code_001622E8*)((char*)pkt + 8);
    unsigned int n = 0;
    int k = -1;
    int removed = 0;
    unsigned int* head = 0;
    int on = 1;
    Code_001622E8* end = (Code_001622E8*)((char*)pkt + (pkt->s.h0 * 16 + 16));
    unsigned int nreg = 0;
    while (c < end) {
        if ((c->b[3] & 0x60) == 0x60) {
            unsigned short h = c->s.h0;
            c->s.h0 = ((h - removed) & 0x3FF) | (h & 0xFC00);
            if (c->s.h2 == 0x6C01 && c->s.w4 == 0x8000) {
                if (c->s.w8 == 0x52)
                    removed = 0;
            }
            if (D_003942DC == 1 && !(D_003942E0 < 2) && on) {
                if (k == -1) {
                    head = &c->s.w4;
                    n = c->s.w4 & 0x7FFF;
                    nreg = head[1] >> 28;
                } else {
                    marks[k] = c;
                }
                k++;
            }
        } else if ((c->b[3] & 0x7F) == 0x14) {
            on = 1;
        }
        c = func_00164D20(c);
        if (k == 5) {
            unsigned int* da = &marks[0]->s.w4;
            unsigned char* db = (unsigned char*)&marks[1]->s.w4;
            unsigned short* dc = (unsigned short*)&marks[2]->s.w4;
            unsigned int* dd = &marks[3]->s.w4;
            unsigned int* de = &marks[4]->s.w4;
            unsigned int* sa = da;
            unsigned char* sb = db;
            unsigned short* sc = dc;
            unsigned int* sd = dd;
            unsigned int* se = de;
            k = 1;
            if ((marks[0]->b[3] & 7) == 4)
                k = 2;
            unsigned int drop = 0;
            unsigned int i;
            for (i = 0; i < n; i++) {
                if ((i <= n - 3 && (se[1] & 0x80000000) && (se[3] & 0x80000000) && (se[5] & 0x80000000))
                    || (i == n - 2 && (se[1] & 0x80000000) && (se[3] & 0x80000000))
                    || (i == n - 1 && (se[1] & 0x80000000))) {
                    sa += k;
                    sb += 3;
                    sc += 3;
                    sd++;
                    se += 2;
                    drop++;
                } else if (se != de) {
                    *da++ = *sa++;
                    if (k == 2)
                        *da++ = *sa++;
                    *db++ = *sb++;
                    *db++ = *sb++;
                    *db++ = *sb++;
                    *dc++ = *sc++;
                    *dc++ = *sc++;
                    *dc++ = *sc++;
                    *dd++ = *sd++;
                    *de++ = *se++;
                    *de++ = *se++;
                } else {
                    se += 2;
                    sa += k;
                    sb += 3;
                    sc += 3;
                    sd++;
                    da += k;
                    db += 3;
                    dc += 3;
                    dd++;
                    de = se;
                }
            }
            n -= drop;
            if (n < 2) {
                unsigned int pad = 2 - n;
                db += pad * 3;
                dc += pad * 3;
                da += pad * k;
                drop += n - 2;
                n = 2;
                dd += pad;
                de += pad * 2;
            }
            for (i = 0; i < 5; i++)
                marks[i]->b[2] = n;
            for (i = 0; i < drop; i++) {
                *da++ = 0;
                if (k == 2)
                    *da++ = 0;
                *db++ = 0;
                *db++ = 0;
                *db++ = 0;
                *dc++ = 0;
                *dc++ = 0;
                *dc++ = 0;
                *dd++ = 0;
                *de++ = 0;
                *de++ = 0;
            }
            head[0] = (head[0] & 0xFFFF8000) | n;
            head[3] = n * nreg;
            removed += drop * 5;
            k = -1;
            on = 0;
        }
    }
    unsigned short h = pkt->s.h2;
    pkt->s.h2 = ((h - removed) & 0x3FF) | (h & 0xFC00);
}
