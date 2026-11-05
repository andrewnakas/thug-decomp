struct Req_00111738 {
    char pad[0x10];
    int m10;
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

struct Job_00111738 {
    char pad[0x1C];
    int m1C;
    char pad20[0x3C - 0x20];
    int m3C;
};

extern "C" int func_00112238(Req_00111738* req, Job_00111738* job, int a, int b);
extern "C" int func_0010E4B0(Job_00111738* job);

extern "C" void func_00111738(Job_00111738* job, int arg)
{
    Req_00111738 req;
    req.m6C = 6;
    req.m10 = job->m3C;
    req.m14 = 3;
    req.m18 = arg;
    func_00112238(&req, job, 1, -1);
    if (job->m1C) {
        func_0010E4B0(job);
    }
}
