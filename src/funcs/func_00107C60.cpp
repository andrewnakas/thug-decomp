extern "C" int func_0031A350(int a, int b);

struct Snd_00107C60 {
    char pad0[0x10];
    int m10;
    int m14;
    char pad18[0xDC - 0x18];
    int mDC;
    void Stop();
};

void Snd_00107C60::Stop()
{
    if (mDC == 2) func_0031A350(m10, m14);
    mDC = 0;
}
