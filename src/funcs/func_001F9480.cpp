extern "C" void* func_003315B8(void* p, int c, unsigned int n);

struct Sample_001F9480 {
    int m0;
    int m4;
    int m8;
};

class Stats_001F9480 {
public:
    int m0;
    Sample_001F9480 m4[256];
    int mC04;
    char mC08[0x400];
    char m1008[0x400];
    int m1408;
    int m140C;
    Stats_001F9480();
};

Stats_001F9480::Stats_001F9480()
{
    mC04 = 0;
    m1408 = 0;
    m140C = 0;
    func_003315B8(mC08, 0, 0x400);
    func_003315B8(m1008, 0, 0x400);
}
