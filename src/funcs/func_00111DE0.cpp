extern volatile int D_00388C90;

struct Req_00111DE0 {
    char pad[0x10];
    int m10;
    char pad14[0x6C - 0x14];
    int m6C;
};

struct Job_00111DE0 {
    char pad[0x1C];
    int m1C;
    char pad20[0x34 - 0x20];
    volatile int m34;
    char pad38[0x3C - 0x38];
    volatile int m3C;
    int Bump() { return ++m34; }
    bool Close();
};

extern "C" int func_00112238(Req_00111DE0* req, Job_00111DE0* job, int a, int b);
extern "C" int func_0010E4B0(Job_00111DE0* job);

bool Job_00111DE0::Close()
{
    Req_00111DE0 req;
    req.m6C = 2;
    req.m10 = m3C;
    D_00388C90++;
    Bump();
    func_00112238(&req, this, 1, -1);
    m3C = -1;
    if (m1C) {
        return func_0010E4B0(this) != 0;
    }
    return false;
}
