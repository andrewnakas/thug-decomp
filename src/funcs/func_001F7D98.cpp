extern "C" int func_00103F28(char*, ...);

extern char D_003664B8[];
extern char D_003664F0[];
extern char D_00366630[];

struct Hdr_001F7D98 {
    int m0;
    char m4[4];
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    char m24[4];
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
};

void func_001F7D98(Hdr_001F7D98* h, int n)
{
    if (!h->m0) {
        int room = 0x28 - h->m2C;
        int k = (room < n) ? room : n;
        h->m2C += k;
        if (h->m2C >= 0x28) {
            h->m0 = 1;
            func_00103F28(D_003664B8);
            func_00103F28(D_003664F0, h->m4[0], h->m4[1], h->m4[2], h->m4[3], h->m8, h->mC, h->m10, h->m14, h->m18, h->m1C, h->m20);
            func_00103F28(D_00366630, h->m24[0], h->m24[1], h->m24[2], h->m24[3], h->m28);
        }
        n -= k;
    }
    h->m34 = (h->m34 + n) % h->m3C;
    h->m38 += n;
    h->m40 += n;
}
