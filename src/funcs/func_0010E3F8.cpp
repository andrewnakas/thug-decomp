class Job_0010E3F8 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    volatile int m1C;
    int m20;
    int m24;
    volatile int m28;
    volatile int m2C;
    int m30;
    volatile int m34;
    virtual void V1();
    virtual void V2();
    virtual void OnReset();
    void Reset();
};

void Job_0010E3F8::Reset()
{
    m28 = -1;
    m2C = -1;
    m34 = 0;
    m1C = 1;
    m20 = 0x10000;
    m24 = 100;
    m4 = 0;
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m0 = 0;
    m30 = 0;
    OnReset();
}
