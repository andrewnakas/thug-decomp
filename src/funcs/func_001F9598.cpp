struct Sample_001F9598 {
    int m0;
    int m4;
    int m8;
};

extern "C" void func_001F9678(Sample_001F9598*, int);
extern "C" void func_001F9680(Sample_001F9598*, int);

struct Stats_001F9598 {
    int m0;
    Sample_001F9598 m4[256];
    int mC04;
    char m_pad[0x1408 - 0xC08];
    int m1408;
    int m140C;
};

void func_001F9598(Stats_001F9598* s, int bytes, int time)
{
    int idx = s->mC04 % 256;
    Sample_001F9598* e = &s->m4[idx];
    func_001F9678(e, bytes);
    func_001F9680(e, time);
    s->m1408 += bytes;
    s->mC04++;
}
