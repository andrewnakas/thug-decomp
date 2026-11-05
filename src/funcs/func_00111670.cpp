struct Req_00111670 {
    char pad[0x10];
    int m10;
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

struct Job_00111670 {
    char pad[0x1C];
    int m1C;
    char pad20[0x3C - 0x20];
    int m3C;
};

extern "C" int func_00112238(Req_00111670* req, Job_00111670* job, int a, int b);
extern "C" int func_0010E4B0(Job_00111670* job);

extern "C" void func_00111670(Job_00111670* job, int arg)
{
    Req_00111670 req;
    req.m10 = job->m3C;
    req.m14 = 0;
    req.m18 = arg;
    req.m6C = 6;
    func_00112238(&req, job, 1, -1);
    if (job->m1C) {
        func_0010E4B0(job);
    }
}
