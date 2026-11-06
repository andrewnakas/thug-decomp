extern volatile int D_00388C90;

struct Req_00111A00 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    void* m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

struct Job_00111A00 {
    char pad[0x34];
    volatile int m34;
    char pad38[0x3C - 0x38];
    volatile int m3C;
    int Bump() { return ++m34; }
    void Read(void* buf, int size, int count);
};

extern "C" void func_0031BF20(int a);
extern "C" int func_00112238(Req_00111A00* req, Job_00111A00* job, int a, int b);
extern "C" void func_00112378(int id);
extern "C" void func_001123B8(int a);

void Job_00111A00::Read(void* buf, int size, int count)
{
    Req_00111A00 req;
    req.m6C = 4;
    req.m10 = m3C;
    req.m14 = buf;
    req.m18 = size * count;
    D_00388C90++;
    Bump();
    func_0031BF20(0);
    func_00112378(func_00112238(&req, this, 1, -1));
    func_001123B8(req.mC);
}
