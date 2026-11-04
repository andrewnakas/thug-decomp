struct Sample_001F94D0 {
    int m0;
    int m4;
    int m8;
};

extern "C" int func_001F9670(Sample_001F94D0*);
extern "C" int func_001F9668(Sample_001F94D0*);

struct Stats_001F94D0 {
    int m0;
    Sample_001F94D0 m4[256];
    int mC04;
    char m_pad[0x1408 - 0xC08];
    int m1408;
    int m140C;
};

void func_001F94D0(Stats_001F94D0* s, int now)
{
    int total = 0;
    for (int i = 0; i < 0x100 && i < s->mC04; i++) {
        Sample_001F94D0* e = &s->m4[i];
        if (now - func_001F9670(e) < 1000)
            total += func_001F9668(e);
    }
    s->m140C = total;
}
