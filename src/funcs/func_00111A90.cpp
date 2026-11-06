extern volatile int D_00388C90;

struct Req_00111A90 {
    char pad[0x10];
    int m10;
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

struct Job_00111A90 {
    char pad[0x1C];
    volatile int m1C;
    char pad20[0x28 - 0x20];
    volatile int m28;
    volatile int m2C;
    char pad30[4];
    volatile int m34;
    int Bump() { return ++m34; }
    char pad38[0x3C - 0x38];
    volatile int m3C;
    int Seek(long offset, int whence);
};

extern "C" int func_00112238(Req_00111A90* req, Job_00111A90* job, int a, int b);
extern "C" int func_0010E4B0(Job_00111A90* job);

int Job_00111A90::Seek(long offset, int whence)
{
    Req_00111A90 req;
    req.m6C = 5;
    req.m10 = m3C;
    req.m14 = offset;
    req.m18 = whence;
    D_00388C90++;
    Bump();
    func_00112238(&req, this, 1, -1);
    if (m1C) {
        return func_0010E4B0(this);
    }
    return 0;
}
